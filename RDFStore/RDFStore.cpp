#include "RDFStore.h"

//lunghezza buffer dove sono salvati risultati query
const int LENGTH = 100;

RDFStore::RDFStore(){
	this->store = new RDFoxDataStore;
	this->numVars = new size_t;
	this->isQueryMatched = new size_t;
	this->resourceIDs = new RDFoxDataStoreResourceID;
	this->datatypeID = new RDFoxDataStoreDatatypeID;
	this->resBuffer = new char[LENGTH];
	this->bufferLength = new size_t;
	this->queryIterator = new RDFoxDataStoreTupleIterator;
	RDFoxDataStore_Create(this->store, this->type, this->parametersArray , 0);
	RDFoxDataStore_Initialize(*(this->store));
	std::cout << "1. Inizializzato un Data Store di tipo " << this->type << "\n";
	RDFoxDataStore_ImportFile(*(this->store), this->kb , 0, false);
	std::cout << "2. Import file kbradio (triple importate ma non materializzate)\n";
	RDFoxDataStore_ImportFile(*(this->store), this->dlogRule , 0, false);
	std::cout << "3. Import file regole datalog\n";
	RDFoxDataStore_ApplyRules(*(this->store), false);
	std::cout << "4. Materializzazione triple...\n";
}

RDFStore::~RDFStore(){
	delete this->store;
	delete this->numVars;
	delete this->isQueryMatched;
	delete this->resourceIDs;
	delete this->datatypeID;
	delete[] this->resBuffer;
	delete this->bufferLength;	
	delete this->queryIterator;
	for (std::map<int,RuleQuery*>::iterator query = this->queries.begin(); query != this->queries.end(); query++){	
		delete query->second;
	}
}

std::vector<std::string> getVars(std::string query, int all){
	std::vector<std::string> var;
	std::string temp;
	int isNewVar = 1;

	for(std::string::iterator it=query.begin(); it!=query.end(); it++){
		if(*it == '?' || *it == '$'){//trovata variabile, inizio a scansionare il nome
			it++;
			while (*it != ' '){
				temp.push_back(*it);
				it++;
			}
			if(all == 1){//controllo di non aver duplicato variabili (nel pattern posso scrivere più volte la stessa var)
				for(std::vector<std::string>::iterator itVars=var.begin(); itVars!=var.end(); itVars++){
					if(temp.compare(*itVars) == 0){
						isNewVar = 0;
						break;//duplicato sicuro, posso uscire dal for
					}
				}
			}
			if(isNewVar == 1){
				var.push_back(temp);
			}
			isNewVar = 1;
			temp.clear();
		}
	}
	return var;
}

//RDFox "select *" queries not properly working... (?s ?p ?o -> resource[0]=?p, [1]=?o, [2]=?s )
std::vector<std::string> findVars(const char* query){
	std::string temp = query;
	std::string querystring = query;
	unsigned inizio, fine;
	size_t found;
  
	std::transform(querystring.begin(), querystring.end(), temp.begin(), ::tolower);
	inizio = temp.find("select");
	fine = temp.find(" where");
	std::string nuova = querystring.substr(inizio+7, (fine-7)-inizio+1);
	//RDFox con select * li prende "a caso" (resource[0] è predicate, [1] object, [2] subject ecc), meglio specificare ogni singola var
	found = nuova.find_first_of("*");
	if(found != std::string::npos){
		return getVars(querystring.substr(querystring.find_first_of("{"), querystring.find_last_of("}")-querystring.find_first_of("{")+1), 1);
	}else{
		return getVars(nuova, 0);
	}
}

void RDFStore::addQuery(int type, const char* name, const char* string, const char** prefixesArray, int prefixesLength){
	RuleQuery *temp = new RuleQuery;
	temp->eventType = type;
	temp->queryName = name;
	temp->queryString = string;
	temp->vars = findVars(string);
	temp->prefixesArray = prefixesArray;
	temp->prefixesLength = prefixesLength;
	queries.insert(std::pair<int, RuleQuery*>(type, temp));
}

/*Import update: 0 ADD
*                1 SCHEDULE_FOR_ADDITION
*		 2 SCHEDULE_FOR_DELETION 
* See RDFox: Common.h
*/
std::vector<Event*> RDFStore::processRdfEvent(const char* event){
	std::vector<Event*> teslaEvents;	
	if(this->eventOld != NULL){
		RDFoxDataStore_ImportFile(*(this->store), this->eventOld , 2, false);//delete evento precedente
	}
	RDFoxDataStore_ImportFile(*(this->store), event , 1, false);//add nuovo evento
	RDFoxDataStore_ApplyRules(*(this->store), true); //true = incrementally
	this->eventOld = event;
	teslaEvents = evaluateQueries();
	return teslaEvents;
}

//Ottimizzazione: ciclo for sulle sole query da valutare (<--info dagli FSA di TRex)
std::vector<Event*> RDFStore::evaluateQueries(){
	std::vector<Event*> allEvents;
	std::vector<Event*> singleQueryEvents;
	for (std::map<int,RuleQuery*>::iterator query = this->queries.begin(); query != this->queries.end(); query++){
		singleQueryEvents = evaluateSingleQuery(query->second);
		for(std::vector<Event*>::iterator it = singleQueryEvents.begin() ; it != singleQueryEvents.end(); it++){
			allEvents.push_back(*it);
		}
	}
	return allEvents;
}

std::vector<Event*> RDFStore::evaluateSingleQuery(RuleQuery* q){
	std::vector<Event*> events;
	Resource *tempRes;
	Event *tempEvent;								
	RDFoxDataStoreTupleIterator_CompileQuery(queryIterator,*(this->store), q->queryString, NULL, 0, q->prefixesArray, q->prefixesLength);
	RDFoxDataStoreTupleIterator_GetArity(this->numVars, *(this->queryIterator));
	RDFoxDataStoreTupleIterator_Open(this->isQueryMatched, *(this->queryIterator), *(this->numVars), this->resourceIDs);
	while(*(this->isQueryMatched) != 0){
		tempEvent = new Event;
		tempEvent->eventType = q->eventType;
		tempEvent->prefixesArray = q->prefixesArray;
		tempEvent->prefixesLength = q->prefixesLength;
		for(unsigned int j = 0; j < *(this->numVars); j++){
			tempRes = new Resource;
			tempRes->lexicalForm = new char[LENGTH];
			//chiamata doppia perchè stampa male i risultati nel buffer (bug di RDFox?)
			RDFoxDataStoreTupleIterator_GetResource(*queryIterator, resourceIDs[j], datatypeID, resBuffer, bufferLength);
			RDFoxDataStoreTupleIterator_GetResource(*queryIterator, resourceIDs[j], datatypeID, resBuffer, bufferLength);
			strcpy(tempRes->lexicalForm, this->resBuffer);	
			tempRes->datatypeID = *(this->datatypeID);
			tempEvent->attributes.insert(std::pair<const char*, Resource*>(q->vars[j].c_str(),tempRes));
		}
		events.push_back(tempEvent);
		RDFoxDataStoreTupleIterator_GetNext(this->isQueryMatched, *(this->queryIterator), *(this->numVars), this->resourceIDs);
	}
	return events;
}
