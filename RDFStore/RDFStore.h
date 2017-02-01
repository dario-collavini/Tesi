#ifndef RDFSTORE_H_
#define RDFSTORE_H_

#include <CppRDFox/RDFoxDataStore.h>
#include "../Common/RDFStructures.h"
#include <algorithm>
#include <iostream>
#include <string.h>

class RDFStore {
public:
	RDFStore();

	~RDFStore();

	RDFoxDataStore getStore(){return *store;}
	
	void addQuery(int eventType, const char* queryName, const char* queryString, const char** prefixesArray, int prefixesLength);

	std::map<int, RuleQuery*>& getQueryMap(){return queries;}

	std::vector<Event*> processRdfEvent(const char* event);

private:	
	RDFoxDataStore *store;
	const char** parametersArray = new const char*;
	const char* type = "seq";
	const char* kb = "/home/dario/Scrivania/RDFoxProva/CppRDFox/file/kbradio.ttl";
	const char* dlogRule = "/home/dario/Scrivania/RDFoxProva/CppRDFox/file/inf.dlog";
	//se voglio salvare copia db: const char* kbsave = "/home/dario/Scrivania/RDFoxProva/CppRDFox/file/provakb";
	// RDFoxDataStore_Save(RDFoxDataStore, const char* const fileName);
	std::map<int, RuleQuery*> queries;
	const char* eventOld = NULL;
	
	//variabili per valutare query
	size_t* numVars;
	size_t* isQueryMatched;
	RDFoxDataStoreResourceID* resourceIDs;
	RDFoxDataStoreDatatypeID* datatypeID;
	char* resBuffer;
	size_t* bufferLength;
	RDFoxDataStoreTupleIterator* queryIterator;
	
	void initialize();

	std::vector<Event*> evaluateQueries();

	std::vector<Event*> evaluateSingleQuery(RuleQuery* q);

};
#endif /*RDFSTORE_H*/
