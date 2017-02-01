/**Classe di supporto per "bypassare" il nuovo parser necessario**/

#ifndef PARSER_EMULATOR_H
#define PARSER_EMULATOR_H

#include <TRex2/Packets/RulePkt.h>
#include <TRex2/Packets/RulePktValueReference.h>
#include <TRex2/Common/Structures.h>
#include <TRex2/Common/Consts.h>
#include <TRex2/Common/OpTree.h>
#include <TRex2/Common/CompositeEventTemplate.h>
#include <vector>
#include "../Common/RDFStructures.h"

class ParserEmulator {
public:
	
	RulePkt * parseRule();

	int parseQueryType(int type);
	
	const char* parseQueryName(int type);

	const char* parseQueryString(int type);

	const char** parsePrefixesArray();

	Template* parseTemplateCE();

private:
	const char * prefixesArray[4] = {"ad:", "http://my.org#", "a1:", "http://localhost#"};

};



#endif /*PARSER_EMULATOR_H*/
