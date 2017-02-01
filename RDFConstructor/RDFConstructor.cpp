#include "RDFConstructor.h"

RDFConstructor::RDFConstructor(){
	this->trexListener = new TRexListener(this);
}

RDFConstructor::~RDFConstructor(){
	for(std::map<int, Template*>::iterator it=rdfEventTemplates.begin(); it !=rdfEventTemplates.end(); it++){
		delete it->second;
	}
	delete trexListener;
}
