#include "RDFTRexRuleParser.h"

//max len TRex vars
const int SIZE = 16;

void RDFTRexRuleParser::enterEvent_declaration(RDFTESLAParser::Event_declarationContext * ctx){
	eventId_map.insert(std::pair<std::string, int>(ctx->EVT_NAME()->getText(), stoi(ctx->INT_VAL()->getText())));
}

bool checkAllWithin(RDFTESLAParser::Positive_predicateContext* ctx){
	std::string sel = ctx->SEL_POLICY()->getText();
	if(sel.compare("all") == 0)
		return true;
	else
		return false;
}

CompKind getCompKind(RDFTESLAParser::Positive_predicateContext* ctx) {
		std::string sel = ctx->SEL_POLICY()->getText();
		if(sel.compare("each") == 0 || sel.compare("all") == 0 ) return EACH_WITHIN;
		else if (sel.compare("last") == 0)  return LAST_WITHIN;
		else if (sel.compare("first") == 0) return FIRST_WITHIN;
		else return EACH_WITHIN;
	}

//Template memory freed by destructor of RDFConstructor
void RDFTRexRuleParser::enterCe_definition(RDFTESLAParser::Ce_definitionContext * ctx){
	int type = eventId_map.find(ctx->EVT_NAME()->getText())->second;
	templateCE = new Template;
	templateCE->eventType = type;
	templateCE->isRuleAllWithin = false;//change on the go...
	rule = new RulePkt(false);//deleted later from TRexEngine
	ceTRex = new CompositeEventTemplate(type);
	rule->setCompositeEventTemplate(ceTRex);
	RDFTESLAParser::Rdf_patternContext* pattern = ctx->rdf_pattern();
	std::vector<RDFTESLAParser::TripleContext*> tripleList = pattern->triple();
	for(std::vector<RDFTESLAParser::TripleContext*>::iterator triple = tripleList.begin(); triple != tripleList.end(); triple++){
		TripleTemplate t;
		RDFTESLAParser::SubContext* subject = (*triple)->sub();
		RDFTESLAParser::PredContext* predicate = (*triple)->pred();
		RDFTESLAParser::ObjContext* object = (*triple)->obj();
		if(subject->uri() != NULL){//it is not a var, just copy the uri
			t.subject = std::make_pair(IS_NOT_VAR, subject->uri()->getText());
		}else if(subject->SPARQL_VAR()!= NULL){//it is a var
			t.subject = std::make_pair(IS_VAR, subject->SPARQL_VAR()->getText());
		}
		if(predicate->uri() != NULL){//it is not a var, just copy the uri
			t.predicate = std::make_pair(IS_NOT_VAR, predicate->uri()->getText());
		}else if(predicate->SPARQL_VAR()!= NULL){//it is a var
			t.predicate = std::make_pair(IS_VAR, predicate->SPARQL_VAR()->getText());
		}
		if(object->uri() != NULL){//it is not a var, just copy the uri
			t.object = std::make_pair(IS_NOT_VAR, object->uri()->getText());
		}else if(object->SPARQL_VAR()!= NULL){//it is a var
			t.object = std::make_pair(IS_VAR, object->SPARQL_VAR()->getText());
		}
		templateCE->triples.push_back(t);
	}
}

void RDFTRexRuleParser::enterTerminator(RDFTESLAParser::TerminatorContext * ctx){
	int eventType = eventId_map.find(ctx->predicate()->EVT_NAME()->getText())->second;
	if(ctx->predicate()->SPARQL_QUERY() != NULL){
		std::string query = ctx->predicate()->SPARQL_QUERY()->getText();
		query.erase(0,1);//erase '['
		query.erase(query.end()-1, query.end());//erase ']'
		queries.push_back(std::make_tuple(eventType, ctx->predicate()->EVT_NAME()->getText(), query));
		if(ctx->predicate()->event_alias() != NULL){
			eventId_map.insert(std::pair<std::string, int>(ctx->predicate()->event_alias()->EVT_NAME()->getText(), eventType));
		}
	}
	rule->addRootPredicate(eventType, NULL, 0);
	predicatesIds.insert(std::make_pair(ctx->predicate()->EVT_NAME()->getText(), predicateCount));//predicateCount = 0 here
	predicateCount++;
}

void RDFTRexRuleParser::enterPositive_predicate(RDFTESLAParser::Positive_predicateContext * ctx){
	int eventType = eventId_map.find(ctx->predicate()->EVT_NAME()->getText())->second;
	int predId = predicatesIds.find(ctx->EVT_NAME()->getText())->second;
	if(ctx->predicate()->SPARQL_QUERY() != NULL){
		std::string query = ctx->predicate()->SPARQL_QUERY()->getText();
		query.erase(0,1);//erase '['
		query.erase(query.end()-1, query.end());//erase ']'
		queries.push_back(std::make_tuple(eventType, ctx->predicate()->EVT_NAME()->getText(), query));
		if(ctx->predicate()->event_alias() != NULL){
			eventId_map.insert(std::pair<std::string, int>(ctx->predicate()->event_alias()->EVT_NAME()->getText(), eventType));
		}
	}
	if(checkAllWithin(ctx)){
		templateCE->isRuleAllWithin = true;
	}
	TimeMs time(stoi(ctx->INT_VAL()->getText()));
	rule->addPredicate(eventType, NULL, 0, predId-1, time, getCompKind(ctx));
	predicatesIds.insert(std::make_pair(ctx->predicate()->EVT_NAME()->getText(), predicateCount));
	predicateCount++;
}

void RDFTRexRuleParser::enterNegative_predicate(RDFTESLAParser::Negative_predicateContext * ctx){
	int eventType = eventId_map.find(ctx->predicate()->EVT_NAME()->getText())->second;
	if(ctx->predicate()->SPARQL_QUERY() != NULL){
		std::string query = ctx->predicate()->SPARQL_QUERY()->getText();
		query.erase(0,1);//erase '['
		query.erase(query.end()-1, query.end());//erase ']'
		queries.push_back(std::make_tuple(eventType, ctx->predicate()->EVT_NAME()->getText(), query));
		if(ctx->predicate()->event_alias() != NULL){
			eventId_map.insert(std::pair<std::string, int>(ctx->predicate()->event_alias()->EVT_NAME()->getText(), eventType));
		}
	}
	RDFTESLAParser::Neg_one_referenceContext* neg_one = ctx->neg_one_reference();
	RDFTESLAParser::Neg_betweenContext* neg_between = ctx->neg_between();
	if(neg_one != NULL){
		int predId = predicatesIds.find(neg_one->EVT_NAME()->getText())->second;
		TimeMs time(stoi(neg_one->INT_VAL()->getText()));
		rule->addTimeBasedNegation(eventType, NULL, 0, predId, time);
	}else if(neg_between != NULL){
		int predId1 = predicatesIds.find(neg_between->EVT_NAME(0)->getText())->second;
		int predId2 = predicatesIds.find(neg_between->EVT_NAME(1)->getText())->second;
		rule->addNegationBetweenStates(eventType, NULL, 0, predId1, predId2);
	}
}

void RDFTRexRuleParser::enterParametrization(RDFTESLAParser::ParametrizationContext * ctx){
	unsigned int numParam = ctx->packet_reference().size();
	for(unsigned int i = 0; i < numParam; i = i + 2){
		int predId1 = predicatesIds.find(ctx->packet_reference(i)->EVT_NAME()->getText())->second;
		int predId2 = predicatesIds.find(ctx->packet_reference(i+1)->EVT_NAME()->getText())->second;
		std::string var1 = ctx->packet_reference(i)->SPARQL_VAR()->getText();
		std::string var2 = ctx->packet_reference(i+1)->SPARQL_VAR()->getText();
		char* v1 = new char[SIZE];//freed by TRex?
		char* v2 = new char[SIZE];
		strcpy(v1, var1.c_str());
		strcpy(v2, var2.c_str());
		rule->addParameterBetweenStates(predId1, v1+1, predId2, v2+1);//+1 drop the '?' or '$'
	}
}

void RDFTRexRuleParser::enterDefinitions(RDFTESLAParser::DefinitionsContext * ctx){
	//STATIC ATTRIBUTES
	unsigned int numAttr = ctx->staticAttr_definition().size();
	for(unsigned int i = 0; i < numAttr; i++){
		Attribute attr;
		RDFTESLAParser::Static_referenceContext* ref = ctx->staticAttr_definition(i)->static_reference();
		std::string name = ctx->staticAttr_definition(i)->SPARQL_VAR()->getText();
		char* varName = new char[SIZE];
		strcpy(varName, name.c_str());
		attr.name = varName;
		if(ref->INT_VAL() != NULL){
			attr.type = INT;
			attr.intVal = stoi(ref->INT_VAL()->getText());
		}else if(ref->FLOAT_VAL() != NULL){
			attr.type = FLOAT;
			attr.floatVal = stof(ref->FLOAT_VAL()->getText());
		}else if(ref->STRING_VAL() != NULL){
			attr.type = STRING;
			std::string string = ref->STRING_VAL()->getText();
			string.erase(0,1);//erase '"'
			string.erase(string.end()-1, string.end());//erase '"'
			attr.stringVal = string.c_str();
		}else if(ref->BOOL_VAL() != NULL){
			attr.type = BOOL;
			if(ref->BOOL_VAL()->getText().compare("true") == 0) attr.boolVal = true;
			else attr.boolVal = false;
		}
		ceTRex->addStaticAttribute(attr);
	}





	//PARAMS/AGGREGATES
}












