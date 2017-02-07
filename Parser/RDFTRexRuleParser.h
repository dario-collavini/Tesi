#include "antlr4-runtime.h"
#include "RDFTESLALexer.h"
#include "RDFTESLAParser.h"
#include "RDFTESLABaseListener.h"
#include "../Common/RDFStructures.h"
#include <TRex2/Packets/RulePkt.h>
#include <TRex2/Common/Consts.h>
#include <TRex2/Common/Structures.h>
#include <string>


class RDFTRexRuleParser : public RDFTESLABaseListener{
public:
	void enterEvent_declaration(RDFTESLAParser::Event_declarationContext* ctx);

	void enterCe_definition(RDFTESLAParser::Ce_definitionContext * ctx);

	void enterTerminator(RDFTESLAParser::TerminatorContext * ctx);

	void enterPositive_predicate(RDFTESLAParser::Positive_predicateContext * ctx);

	void enterNegative_predicate(RDFTESLAParser::Negative_predicateContext * ctx);

	void enterParametrization(RDFTESLAParser::ParametrizationContext * ctx);

	void enterDefinitions(RDFTESLAParser::DefinitionsContext * ctx);



private:
	 std::map<std::string, int> eventId_map;
	 std::map<std::string, int> predicatesIds;
	 int predicateCount = 0;
	 Template* templateCE;
	 CompositeEventTemplate* ceTRex;
	 std::vector<std::tuple<int, std::string, std::string> > queries;
	 RulePkt* rule;

};


//TODO rifare file grammatica RDFTESLA.g4 con antlr(ci sono errori)
