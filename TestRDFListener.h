#ifndef TESTRDFLISTENER_H_
#define TESTRDFLISTENER_H_

#include <TRex2/Packets/SubPkt.h>
#include <TRex2/Packets/PubPkt.h>
#include "RDFConstructor/RDFResultListener.h"
#include "Common/RDFStructures.h"

class TestRDFListener: public RDFResultListener{
public:
	TestRDFListener(SubPkt* subscription);

	virtual ~TestRDFListener();

	virtual void handleResult(RDFEvent* event);

	int getId() {return id;}

private:
	SubPkt* subscription;
	int id;
	void printMessage(std::string msg);
};

#endif /* TESTRDFLISTENER_H_ */
