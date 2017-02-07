#ifndef PARSER_EMULATOR_H
#define PARSER_EMULATOR_H

#include <TRex2/Packets/RulePkt.h>
#include <TRex2/Packets/RulePktValueReference.h>
#include <TRex2/Common/Structures.h>
#include <TRex2/Common/Consts.h>
#include <TRex2/Common/OpTree.h>
#include <TRex2/Common/CompositeEventTemplate.h>
#include "../Common/RDFStructures.h"

/**
 * Temporary class for parsing RDF-Tesla rules.
 */
class ParserEmulator {
public:
	//To TRex
	RulePkt * parseRule();

	//To RDFStore
	int parseQueryType(int type);
	
	const char* parseQueryName(int type);

	const char* parseQueryString(int type);

	//To RDFConstructor
	Template* parseTemplateCE();
};

#endif /*PARSER_EMULATOR_H*/
