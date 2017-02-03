#ifndef RDFSTRUCTURES_H
#define RDFSTRUCTURES_H

#include <TRex2/Packets/PubPkt.h>
#include <vector>
#include <map>
#include <string>

enum IsVar{
	IS_NOT_VAR = 0,
	IS_VAR = 1
};

typedef struct SparqlQuery {
	int eventType;
	const char* queryName;
	const char* queryString;
	const char** prefixesArray;
	int prefixesLength;
	std::vector<std::string> vars;
} RuleQuery;

typedef struct SparqlResource {
	int datatypeID; 	 //tipo risorsa (uri, intero, float, stringa,...) cfr common.h di RDFox
	char* lexicalForm;
} Resource;

typedef struct SparqlAnswer {
	int eventType;				 //tipo evento(== tipo query, da cui ricavo anche il nome)
	std::map<const char*, Resource*> attributes;	 //prendo vettore vars delle query e mappo variabili con attributi
	const char** prefixesArray;		//supporto per la traduzione in eventi Tesla (stringVal degli attributi TRex ha LEN 16 fissata)
	int prefixesLength;
} Event;

typedef struct RDFTripleTemplate {
	std::pair<IsVar, const char*> subject;
	std::pair<IsVar, const char*> predicate;
	std::pair<IsVar, const char*> object;
	bool isPartOfAllWithin;
} TripleTemplate;

typedef struct RDFTemplate {
	int eventType;
	bool isRuleAllWithin;
	std::vector<TripleTemplate> triples;

} Template;

typedef struct RDFDuplicateTriple {
	char* subject;
	char* predicate;
	char* object;
} DuplicateTriple;

typedef struct RDFTriple {
	char* subject;
	char* predicate;
	char* object;
	std::vector<DuplicateTriple> duplicateTriples;
} Triple;

typedef struct ComplexEvent {
	int eventType;
	std::vector<Triple> triples;
	unsigned int numOfDuplicateEvents;//serve solo per regole ALL
	std::vector<std::map<std::string, Attribute>> attributes; //per valutare tutti i constraint
} RDFEvent;

#endif /*RDFSTRUCTURES_H*/
