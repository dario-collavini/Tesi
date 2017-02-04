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
	std::vector<std::string> vars;
} RuleQuery;

typedef struct SparqlResource {
	int datatypeID; 	 //tipo risorsa (uri, intero, float, stringa,...) cfr common.h di RDFox
	char* lexicalForm;
} Resource;

typedef struct SparqlAnswer {
	int eventType;				 //tipo evento(== tipo query, da cui ricavo anche il nome)
	std::map<const char*, Resource*> attributes;	 //prendo vettore vars delle query e mappo variabili con attributi
} Event;

typedef struct RDFTripleTemplate {
	std::pair<IsVar, const char*> subject;
	std::pair<IsVar, const char*> predicate;
	std::pair<IsVar, const char*> object;
} TripleTemplate;

typedef struct RDFTemplate {
	int eventType;
	std::vector<TripleTemplate> triples;
	bool isRuleAllWithin;
} Template;

typedef struct RDFTriple {
	char* subject;
	char* predicate;
	char* object;
} Triple;

typedef struct ComplexEvent {
	int eventType;
	const char** prefixesArray; //passato da rdfstore
	int prefixesArrayLength;//passato da rdfstore
	std::vector<Triple> triples;
	std::vector<std::vector<Triple> > duplicateTriples;//per regole ALL
	std::vector<std::map<std::string, Attribute> > attributes; //per valutare tutti i constraint (vettore di mappe, 0 indice del primo evento, >0 indice degli eventuali duplicati)
} RDFEvent;

#endif /*RDFSTRUCTURES_H*/
