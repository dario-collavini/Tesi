#ifndef RDFRESULTLISTENER_H_
#define RDFRESULTLISTENER_H_

#include "../Common/RDFStructures.h"

class RDFResultListener {
public:
	virtual ~RDFResultListener() { }

	virtual void handleResult(RDFEvent* event) = 0;
};

#endif /*RDFRESULTLISTENER_H_*/
