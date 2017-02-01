#include "ParserEmulator.h"

RulePkt* ParserEmulator::parseRule(){

	/*creo regola di esempio:
	*  Assign 1 = Movement, 2 = High_Radiation, 3 = Warning
	*  define Warning(room = string, value = int)
	*  from Movement(room = $a) and each High_Radiation(value > 100, room = $a) within 5 min from Movement
	*  where room = Movement.room and value = High_Radiation.value
	*/
		
	char stringRoom[] = "room";
	char stringValue[] = "value";
	//char stringSensor[] = "sensor";
	RulePkt *rule = new RulePkt(false);
	Constraint fakeConstr[1];
	strcpy(fakeConstr[0].name, stringRoom);
	fakeConstr[0].type= STRING;
	fakeConstr[0].op = IN;
	strcpy(fakeConstr[0].stringVal, "");
	rule->addRootPredicate(1, fakeConstr, 1);
	
	Constraint c[3];
	strcpy(c[0].name, stringValue);
	c[0].type = INT;
	c[0].op = GT;
	c[0].intVal = 100;
	strcpy(c[1].name, stringRoom);
	c[1].type= STRING;
	c[1].op = IN;
	strcpy(c[1].stringVal, "");
	TimeMs fiveMin(1000*60*5);
	
	rule->addPredicate(2, c, 2, -1, fiveMin, EACH_WITHIN);
	rule->addParameterBetweenStates(0, stringRoom, 1, stringRoom);
	
	//DEFINE + WHERE template evento complesso <---output che poi dovrò passare al rdf constructor(listener)
	CompositeEventTemplate *warn_tmplate = new CompositeEventTemplate(3);

	RulePktValueReference *oproom = new RulePktValueReference(0, stringRoom, STATE);
	RulePktValueReference *oprad = new RulePktValueReference(1, stringValue, STATE);
	//RulePktValueReference *opsensor = new RulePktValueReference(1, stringSensor, STATE);

	OpTree *room = new OpTree(oproom, STRING);
	OpTree *rad = new OpTree(oprad, INT);
	//OpTree *sensor = new OpTree(opsensor, STRING);

	warn_tmplate->addAttribute(stringRoom, room);
	warn_tmplate->addAttribute(stringValue, rad);
	//warn_tmplate->addAttribute(stringSensor, sensor);
	
	rule->setCompositeEventTemplate(warn_tmplate);
	
	return rule;

}


int ParserEmulator::parseQueryType(int type){

	if(type == 1){
		return 1;
	}else{
		return 2;
	}
}


const char* ParserEmulator::parseQueryName(int type){	
	if(type == 1){
		return "Movement";
	}else{
		return "High_Radiation";
	}
}

const char* ParserEmulator::parseQueryString(int type){
	if(type == 1){
		return "select ?room ?bool where{?sensor a1:senstipo a1:MovSens; a1:haslocation ?room; a1:value ?bool.}";
	}else{
		return "select ?sensor ?room ?value where{?sensor a1:senstipo a1:RadSens; a1:haslocation ?room; a1:value ?value. FILTER(?value > 150)}";
	}
}

const char** ParserEmulator::parsePrefixesArray(){
	return prefixesArray;	
}

Template* ParserEmulator::parseTemplateCE(){
	Template* templateCE = new Template;
	templateCE->eventType = 3;
	templateCE->isRuleAllWithin = false;
	TripleTemplate t1, t2;
	t1.subject = std::make_pair(NO_VAR, "a1:stanza");
	t1.predicate = std::make_pair(NO_VAR, "a1:is");
	t1.object = std::make_pair(YES_VAR, "?room");
	t2.subject = std::make_pair(NO_VAR, "a1:radiazioni");
	t2.predicate = std::make_pair(NO_VAR, "a1:is");
	t2.object = std::make_pair(YES_VAR, "?value");
	templateCE->triples.push_back(t1);
	templateCE->triples.push_back(t2);
	
	return templateCE;
}



