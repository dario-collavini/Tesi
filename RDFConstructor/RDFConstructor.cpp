#include "RDFConstructor.h"

//Creates a new TRexlistener, defined as inner member
RDFConstructor::RDFConstructor(){
	this->trexListener = new TRexListener(this);
}

//Frees memory about rdf templates and the TRex listener
RDFConstructor::~RDFConstructor(){
	for(std::map<int, Template*>::iterator it=rdfEventTemplates.begin(); it !=rdfEventTemplates.end(); it++){
		//TODO se ho new delle triple nel parser...altrimenti togliere
		for(std::vector<TripleTemplate>::iterator triple = it->second->triples.begin(); triple != it->second->triples.end(); triple++){
			delete triple->subject.second;
			delete triple->predicate.second;
			delete triple->object.second;
		}
		delete it->second;
	}
	delete trexListener;
}
