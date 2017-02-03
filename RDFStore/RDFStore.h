#ifndef RDFSTORE_H_
#define RDFSTORE_H_

#include <CppRDFox/RDFoxDataStore.h>
#include "../Common/RDFStructures.h"
#include <algorithm>
#include <iostream>
#include <string.h>

//singleton
class RDFStore {
public:

	~RDFStore();

	static RDFStore* getInstance();

	void initialize(const char* type, const char* kb, const char* dlog, const char** prefixes, int prefixesLength);

	void addQuery(int eventType, const char* queryName, const char* queryString);

	const char** getPrefixesArray(){return prefixesArray;}

	int getPrefixesArrayLength(){return prefixesArrayLength;}

	std::vector<Event*> processRdfEvent(const char* event);

protected:

	RDFStore();

private:	
	static RDFStore* instance;
	RDFoxDataStore *store;
	//Parametri pre-processing:
	const char* type;
	const char* kb;
	const char* dlogRules;
	const char** prefixesArray;
	int prefixesArrayLength;
	//se voglio salvare copia db: const char* kbsave = "/home/dario/Scrivania/RDFoxProva/CppRDFox/file/provakb";
	// RDFoxDataStore_Save(RDFoxDataStore, const char* const fileName);
	std::map<int, RuleQuery*> queries;
	const char* eventOld;
	
	//variabili per valutare query
	size_t* numVars;
	size_t* isQueryMatched;
	RDFoxDataStoreResourceID* resourceIDs;
	RDFoxDataStoreDatatypeID* datatypeID;
	char* resBuffer;
	size_t* bufferLength;
	RDFoxDataStoreTupleIterator* queryIterator;

	std::vector<Event*> evaluateQueries();
	std::vector<Event*> evaluateSingleQuery(RuleQuery* q);
};
#endif /*RDFSTORE_H*/
