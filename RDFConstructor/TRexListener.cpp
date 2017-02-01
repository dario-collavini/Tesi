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

RDFEvent* TRexListener::createRDF(PubPkt* pkt){
	RDFEvent* event = new RDFEvent;
	Attribute att;
	char* varName;

	event->eventType = pkt->getEventType();
	Template* templateCE = this->constructor->getRdfEventTemplates().find(pkt->getEventType())->second;
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
		event->attributes.insert(std::make_pair(varName, att)); //salvo attributi per valutare constraint subscription
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
	return event;
}

void TRexListener::notifyRDFListeners(RDFEvent* event){
	for(std::set<RDFResultListener*>::iterator it=constructor->getRDFListeners().begin(); it!=constructor->getRDFListeners().end(); it++) {
		RDFResultListener *listener = *it;
		listener->handleResult(event);
	}
}

void TRexListener::handleResult(std::set<PubPkt *> &genPkts, double procTime){
	bool isEventAll = false;
	bool atLeastOneAll = false;
	std::map<int, std::vector<PubPkt*>> typeOfGroupEvents;
	std::map<int, Template*> templates = this->constructor->getRdfEventTemplates();
	for (std::set<PubPkt*>::iterator i= genPkts.begin(); i != genPkts.end(); i++){
		PubPkt* pubPkt= *i;
		for(std::map<int, Template*>::iterator it = templates.begin(); it != templates.end(); it++){
			int type = pubPkt->getEventType();
			if(type == it->second->eventType && it->second->isRuleAllWithin){
				if(typeOfGroupEvents.find(type) != typeOfGroupEvents.end()){
					//nuovo tipo, aggiungi un vettore di eventi
					std::vector<PubPkt*> eventsToGroup;
					typeOfGroupEvents.insert(std::pair<int, std::vector<PubPkt*>>(type, eventsToGroup.push_back(pubPkt)));
				}else{
					//esiste già il tipo, aggiungilo al vettore esistente
					typeOfGroupEvents.find(type)->second.push_back(pubPkt);
				}
				isEventAll = true;//rimando la creazione dell evento rdf a un'altra funzione...
				atLeastOneAll = true;
			}
		}
		if(isEventAll == false){//pacchetto "singolo" (non ALL), genero RDF
			RDFEvent *rdfEvent = createRDF(pubPkt);
			this->notifyRDFListeners(rdfEvent);
			//notifica fatta, free memoria dell'evento (se il Listener vuole salvarselo lo copia quando lo riceve)
			for(std::vector<Triple>::iterator it = rdfEvent->triples.begin(); it != rdfEvent->triples.end(); it++){
				delete it->subject;
				delete it->predicate;
				delete it->object;
			}
			delete rdfEvent;
		}
		isEventAll = false;//rinizializzata per il prossimo pacchetto
	}
	//TODO:prendi mappa di vettori e passala a funzione incaricata di produrre l'rdf ALL
	//if(atLeastOneAll)createRDFAll(std::map<int, std::vector<PubPkt*>> typeOfGroupEvents);
}
