#ifndef RDFCONSTRUCTOR_H
#define RDFCONSTRUCTOR_H

#include "TRexListener.h"
#include <TRex2/Engine/ResultListener.h>
#include <map>
#include <set>

class RDFConstructor {
public:
	RDFConstructor();

	~RDFConstructor();

	ResultListener* getTRexListener(){return trexListener;}

	std::map<int, Template*> &getRdfEventTemplates(){return rdfEventTemplates;}

	void addTemplate(int type, Template* templateCE) {rdfEventTemplates.insert(std::pair<int, Template*>(type, templateCE));}

	void addRDFListener(RDFResultListener *rdfListener) { rdfListeners.insert(rdfListener); }

	void removeRDFListener(RDFResultListener *rdfListener) { rdfListeners.erase(rdfListener); }

	std::set<RDFResultListener*> &getRDFListeners(){return rdfListeners;}


private:
	ResultListener* trexListener;
	std::map<int, Template*> rdfEventTemplates;
	std::set<RDFResultListener *> rdfListeners;
};
#endif /*RDFCONSTRUCTOR_H*/
