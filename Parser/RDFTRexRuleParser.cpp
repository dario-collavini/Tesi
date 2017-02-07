#include "RDFTRexRuleParser.h"

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












