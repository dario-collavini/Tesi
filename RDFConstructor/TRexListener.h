#ifndef TREXLISTENER_H
#define TREXLISTENER_H

#include <TRex2/Packets/PubPkt.h>
#include <TRex2/Packets/SubPkt.h>
#include <TRex2/Engine/ResultListener.h>
#include "RDFResultListener.h"
#include "RDFConstructor.h"
#include "../Common/RDFStructures.h"
#include <sstream>
#include <set>

class RDFConstructor;

class TRexListener: public ResultListener{
public:
	TRexListener(RDFConstructor* constructor);

	virtual ~TRexListener();
	
	virtual void handleResult(std::set<PubPkt *> &genPkts, double procTime);
	
private:
	RDFConstructor* constructor;

	void notifyRDFListeners(RDFEvent* event);
};
#endif /*TREXLISTENER_H*/
