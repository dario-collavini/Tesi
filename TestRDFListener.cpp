#include "./TestRDFListener.h"

static int lastId= 0;

TestRDFListener::TestRDFListener(SubPkt* subscription):
	subscription(subscription), id(lastId++)
{}

TestRDFListener::~TestRDFListener(){
	delete subscription;
}

bool matches(const Constraint constr, const Attribute attr){
	if (strcmp(constr.name, attr.name)!=0) return false;
	if (constr.type != attr.type) return false;
	switch (constr.type){
	case INT:
		switch (constr.op) {
		case EQ:
			if (attr.intVal!=constr.intVal) return false;
			break;
		case LT:
			if (attr.intVal>=constr.intVal) return false;
			break;
		case GT:
			if (attr.intVal<=constr.intVal) return false;
			break;
		case LE:
			if (attr.intVal>constr.intVal) return false;
			break;
		case GE:
			if (attr.intVal<constr.intVal) return false;
			break;
		
		case NE:
			if (attr.intVal==constr.intVal) return false;
			break;
		case IN:
			throw std::invalid_argument("IN operation cannot be used with INT type");
			break;
		}
		break;
	case FLOAT:
		switch (constr.op) {
		case EQ:
			if (attr.floatVal!=constr.floatVal) return false;
			break;
		case LT:
			if (attr.floatVal>=constr.floatVal) return false;
			break;
		case GT:
			if (attr.floatVal<=constr.floatVal) return false;
			break;
		case LE:
			if (attr.floatVal>constr.floatVal) return false;
			break;
		case GE:
			if (attr.floatVal<constr.floatVal) return false;
			break;

		case NE:
			if (attr.floatVal==constr.floatVal) return false;
			break;
		case IN:
			throw std::invalid_argument("IN operation cannot be used with FLOAT type");
			break;
		}
		break;
	case BOOL:
		switch (constr.op) {
		case EQ:
			if (attr.boolVal!=constr.boolVal) return false;
			break;
		case LT:
			throw std::invalid_argument("LT operation cannot be used with BOOL type");
			break;
		case GT:
			throw std::invalid_argument("GT operation cannot be used with BOOL type");
			break;
		case LE:
			throw std::invalid_argument("LE operation cannot be used with BOOL type");
			break;
		case GE:
			throw std::invalid_argument("GE operation cannot be used with BOOL type");
			break;

		case NE:
			if (attr.boolVal==constr.boolVal) return false;
			break;
		case IN:
			throw std::invalid_argument("IN operation cannot be used with BOOL type");
			break;
		}
		break;
	case STRING:
		switch (constr.op) {
		case EQ:
			if (strcmp(attr.stringVal, constr.stringVal)!=0) return false;
			break;
		case LT:
			if (strcmp(attr.stringVal, constr.stringVal)>=0) return false;
			break;
		case GT:
			if (strcmp(attr.stringVal, constr.stringVal)<=0) return false;
			break;
		case NE:
			if (strcmp(attr.stringVal, constr.stringVal)==0) return false;
			break;
		case LE:
			if (strcmp(attr.stringVal, constr.stringVal)>0) return false;
			break;
		case GE:
			if (strcmp(attr.stringVal, constr.stringVal)<0) return false;
			break;
			
		case IN:
			// The constraint's value should be a substring of the attribute's value:
			// it is a filter specified for published events' attributes
			if (strstr(attr.stringVal, constr.stringVal)==NULL) return false;
			break;
		}
		break;
	}

	return true;
}

bool matches(SubPkt* sub, RDFEvent* event){
	if (event->eventType!=sub->getEventType()) return false;
	for (int i=0; i<sub->getConstraintsNum(); i++){
		Constraint constr= sub->getConstraint(i);
		if(strcmp(event->attributes[constr.name].name, constr.name) != 0) return false;
		if(!matches(constr, event->attributes[constr.name])) return false;
	}
	return true;
}


//la memoria relativa all'evento viene liberata, se voglio processare ulteriormente devo salvarmi una copia dell'evento
void TestRDFListener::handleResult(RDFEvent* event){
	if(matches(subscription, event)){	
		printMessage("New complex event created:");
		std::cout <<"{";
		for(std::vector<Triple>::iterator it = event->triples.begin();it != event->triples.end();it++){
			std::cout << it->subject << " ";
			std::cout << it->predicate << " ";
			std::cout << it->object;
			if(it < event->triples.end()-1) std::cout << ".\n";
			else std::cout << ".";
		}
		std::cout << "}\n";
	}
}

void TestRDFListener::printMessage(std::string msg){
	std::cout << "TestRDFListener" << id << " > " << msg << std::endl;
}

