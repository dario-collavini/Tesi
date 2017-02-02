#include "TRexListener.h"

const int LEN = 16; //lunghezza char risultati trex

TRexListener::TRexListener(RDFConstructor* constructor){
	this->constructor = constructor;
}	

TRexListener::~TRexListener(){
}

std::string getValue(Attribute att){
	std::string result;
	switch(att.type){
		case INT:
			result = static_cast<std::ostringstream*>( &(std::ostringstream() << att.intVal) )->str();
			break;
		case FLOAT:
			result = static_cast<std::ostringstream*>( &(std::ostringstream() << att.floatVal) )->str();
			break;
		case BOOL:
			result = static_cast<std::ostringstream*>( &(std::ostringstream() << att.boolVal) )->str();
			break;
		case STRING:
			result = att.stringVal;
			break;
	}
	return result;
}

RDFEvent* createRDF(PubPkt* pkt, Template* templateCE){
	RDFEvent* event = new RDFEvent;
	Attribute att;
	char* varName;
	std::map<std::string, Attribute> attributesMap;

	event->eventType = pkt->getEventType();
	event->numOfDuplicateEvents = 0;
	//TODO:attaccare prefissi sparql al pattern
	for(std::vector<TripleTemplate>::iterator it =templateCE->triples.begin(); it != templateCE->triples.end(); it++){
		Triple t;
		t.subject = new char[LEN];
		t.predicate = new char[LEN];
		t.object = new char[LEN];
		strcpy(t.subject, it->subject.second);
		strcpy(t.predicate, it->predicate.second);
		strcpy(t.object, it->object.second);
		event->triples.push_back(t);
	}
	for(int i = 0; i < pkt->getAttributesNum(); i++){
		att = pkt->getAttribute(i);
		varName = att.name;
		attributesMap.insert(std::make_pair(varName, att)); //salvo attributi per valutare constraint subscription
		for(unsigned int i = 0; i < templateCE->triples.size(); i++){
			TripleTemplate temp = templateCE->triples[i];
			if(temp.subject.first == 1 && strcmp((temp.subject.second+1), varName) == 0 ){//+1 tolgo il '?' della variabile
				strcpy(event->triples[i].subject, getValue(att).c_str());
			}
			if(temp.predicate.first == 1 && strcmp((temp.predicate.second+1), varName) == 0 ){
				strcpy(event->triples[i].predicate, getValue(att).c_str());
			}
			if(temp.object.first == 1 && strcmp((temp.object.second+1), varName) == 0 ){
				strcpy(event->triples[i].object, getValue(att).c_str());
			}
		}
	}
	event->attributes.push_back(attributesMap);
	return event;
}

std::vector<RDFEvent*> createRDFAll(std::map<int, std::vector<PubPkt*>> typesOfGroupEvents, std::map<int, Template*> templates){
	std::vector<RDFEvent*> results;
	for(std::map<int, std::vector<PubPkt*>>::iterator it = typesOfGroupEvents.begin(); it != typesOfGroupEvents.end(); it++){
		std::vector<PubPkt*> pubPktVector = it->second;
		Template* templateCE = templates.find(it->first)->second;
		unsigned int numOfTriples = templateCE->triples.size();
		RDFEvent* event = new RDFEvent;
		event->eventType = it->first;
		unsigned int numOfPkt =  pubPktVector.size();
		event->numOfDuplicateEvents = numOfPkt-1;//-1 tolto il primo pacchetto!
		for(unsigned int j = 0; j < numOfPkt; j++){
			PubPkt* pubPkt = pubPktVector[j];
			std::map<std::string, Attribute> attributes;
			//copio le singole triple da template all'evento rdf
			for(unsigned int n = 0; n < numOfTriples; n++){
				if(j == 0){//primo set di triple che metto, non ci sono duplicati sicuramente
					Triple t;
					t.subject = new char[LEN];
					t.predicate = new char[LEN];
					t.object = new char[LEN];
					//TODO aggiungere tripla solo se isPartOfAllWithin è true
					strcpy(t.subject, templateCE->triples[n].subject.second);
					strcpy(t.predicate,templateCE->triples[n].predicate.second);
					strcpy(t.object, templateCE->triples[n].object.second);
					event->triples.push_back(t);
				}else{//sto girando il secondo, o più, pacchetto, di sicuro è un duplicato
					DuplicateTriple dt;
					dt.subject = new char[LEN];
					dt.predicate = new char[LEN];
					dt.object = new char[LEN];
					//TODO aggiungere tripla solo se isPartOfAllWithin è true
					strcpy(dt.subject, templateCE->triples[n].subject.second);
					strcpy(dt.predicate,templateCE->triples[n].predicate.second);
					strcpy(dt.object, templateCE->triples[n].object.second);
					event->triples[n].duplicateTriples.push_back(dt);
				}
			}
			//sostituisco le variabili presenti nelle triple
			for(int i = 0; i < pubPkt->getAttributesNum(); i++){
				Attribute att;
				char* varName;
				att = pubPkt->getAttribute(i);
				varName = att.name;
				attributes.insert(std::make_pair(varName, att)); //salvo attributi per valutare constraint subscription
				for(unsigned int k = 0; k < numOfTriples; k++){
					TripleTemplate temp = templateCE->triples[k];
					if(temp.subject.first == 1 && strcmp((temp.subject.second+1), varName) == 0 ){//+1 tolgo il '?' della variabile
						if(j == 0) strcpy(event->triples[k].subject, getValue(att).c_str());
						else strcpy(event->triples[k].duplicateTriples[j-1].subject, getValue(att).c_str());
					}
					if(temp.predicate.first == 1 && strcmp((temp.predicate.second+1), varName) == 0 ){
						if(j == 0) strcpy(event->triples[k].predicate, getValue(att).c_str());
						else strcpy(event->triples[k].duplicateTriples[j-1].predicate, getValue(att).c_str());
					}
					if(temp.object.first == 1 && strcmp((temp.object.second+1), varName) == 0 ){
						if(j == 0) strcpy(event->triples[k].object, getValue(att).c_str());
						else strcpy(event->triples[k].duplicateTriples[j-1].object, getValue(att).c_str());
					}
				}
			}
			event->attributes.push_back(attributes);
		}
		results.push_back(event);
	}
	return results;
}

void TRexListener::notifyRDFListeners(RDFEvent* event){
	for(std::set<RDFResultListener*>::iterator it=constructor->getRDFListeners().begin(); it!=constructor->getRDFListeners().end(); it++) {
		RDFResultListener *listener = *it;
		listener->handleResult(event);
	}
}

void TRexListener::handleResult(std::set<PubPkt *> &genPkts, double procTime){
	bool atLeastOneAll = false;
	std::map<int, std::vector<PubPkt*>> typesOfGroupEvents;
	std::map<int, Template*> templates = this->constructor->getRdfEventTemplates();
	for (std::set<PubPkt*>::iterator i= genPkts.begin(); i != genPkts.end(); i++){
		PubPkt* pubPkt= *i;
		int type = pubPkt->getEventType();
		Template* templateCE = templates.find(type)->second;
		if(templateCE->isRuleAllWithin == true){
			atLeastOneAll = true;//per chiamare la funzione alla fine
			std::map<int, std::vector<PubPkt*>>::iterator it = typesOfGroupEvents.find(type);
			if(it == typesOfGroupEvents.end()){
				//nuovo tipo, aggiungi un vettore di eventi
				std::vector<PubPkt*> eventsToGroup;
				eventsToGroup.push_back(pubPkt);
				typesOfGroupEvents.insert(std::pair<int, std::vector<PubPkt*>>(type, eventsToGroup));
			}else{
				//esiste già il tipo, aggiungilo al vettore esistente
				it->second.push_back(pubPkt);
			}
		}else{//la regola non è ALL
			//pacchetto "singolo" (non ALL), genero RDF
			RDFEvent *rdfEvent = createRDF(pubPkt, templateCE);
			this->notifyRDFListeners(rdfEvent);
			//notifica fatta, free memoria dell'evento (se il Listener vuole salvarselo lo copia quando lo riceve)
			for(std::vector<Triple>::iterator it = rdfEvent->triples.begin(); it != rdfEvent->triples.end(); it++){
				delete it->subject;
				delete it->predicate;
				delete it->object;
			}
			delete rdfEvent;
		}
	}
	if(atLeastOneAll == true){
	   std::vector<RDFEvent*> rdfEventsAll = createRDFAll(typesOfGroupEvents, templates);
	   for(std::vector<RDFEvent*>::iterator event = rdfEventsAll.begin(); event != rdfEventsAll.end(); event++){
		   this->notifyRDFListeners(*event);
		   for(std::vector<Triple>::iterator triple = (*event)->triples.begin(); triple != (*event)->triples.end(); triple++){
			   delete triple->subject;
		   	   delete triple->predicate;
		   	   delete triple->object;
		   	   for(std::vector<DuplicateTriple>::iterator dupTriple = (*triple).duplicateTriples.begin(); dupTriple != (*triple).duplicateTriples.end(); dupTriple++){
		   		   delete dupTriple->subject;
		   		   delete dupTriple->predicate;
		   		   delete dupTriple->object;
		   	   }
		   }
		   delete *event;
	   }
	}
}
