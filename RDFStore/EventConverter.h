#ifndef EVENTCONVERTER_H
#define EVENTCONVERTER_H

#include <TRex2/Packets/PubPkt.h>
#include "RDFStore.h"
#include <vector>
#include <string>

class EventConverter {
public:
	std::vector<PubPkt*> convertToTesla(std::vector<Event*> events);
};
#endif /*EVENTCONVERTER_H*/
