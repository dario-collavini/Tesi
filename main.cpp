#include <TRex2/Engine/TRexEngine.h>
#include <TRex2/Engine/ResultListener.h>
#include <TRex2/Packets/SubPkt.h>
#include <TRex2/Packets/PubPkt.h>
#include "TestRDFListener.h"
#include "RDFStore/RDFStore.h"
#include "RDFStore/EventConverter.h"
#include "Parser/ParserEmulator.h"
#include "Parser/RDFTRexRuleParser.h"
#include "RDFConstructor/RDFConstructor.h"
#include <vector>
#include <fstream>
#include <iostream>

//For print purposes
int a = 1;

void processPubPkt(vector<PubPkt*> pubPkts, TRexEngine* e){
	if(pubPkts.size() == 0) std::cout << "\n\n\n";
	for (vector<PubPkt*>::iterator it= pubPkts.begin(); it != pubPkts.end(); it++){
		std::cout << "...processo pacchetto..." << "\n";
		e->processPubPkt(*it);
	}
	a++;
}

int main(int argc, char* argv[])
{
/*Pre-processing: setting di RDFox e TRex da parte di un server dedicato.
*	RDFox:  		1)creo e inizializzo store con parametri passati;
*					2)import triple ontologia;
*					3)import regole datalog ontologia;
*					4)materializzazione triple (esplicite(=caricate) + implicite(=dedotte da regole)).
*		
*	TRex:			5)inizializzo engine.
*
*	EventConverter: 6)implementa traduzione eventoRDF ----> eventoTesla (lowering rule) 
*/

	const char* type = "seq";
	const char* kb = "./Files/kbradio.ttl";
	const char* dlogRules = "./Files/inf.dlog";
	int prefixesArrayLength = 4;
	const char* prefixesArray[prefixesArrayLength] = {"ad:", "http://my.org#", "a1:", "http://localhost#"};

	RDFStore* store = RDFStore::getInstance();
	store->initialize(type, kb, dlogRules, prefixesArray, prefixesArrayLength);
	TRexEngine* e = new TRexEngine(1);
	RDFConstructor* constructor= new RDFConstructor();
	EventConverter conv;

	e->finalize();
	//Subscription all' rdf constructor, che farà da intermediario tra Trex e il vero listener(client), per produrre il grafo rdf
	e->addResultListener(constructor->getTRexListener());
	
/*Subscription: il client passa subscription e regole al server.
*		Le subscription sono salvate nell'engine, mentre un parser traduce le regole in regole TRex ed estrae le query passandole
*		a RDFox. Passa inoltre il template RDF dell'evento complesso a un componente RDF Constructor, incaricato di produrre l'evento RDF *		corrispondente quando viene generato il corrispondente CE Tesla da TRex.
*/

//Parser
	//1)Rule parsing
	//ParserEmulator parser;
	RDFTRexRuleParser parser;
	//e->processRulePkt(parser.parseRule());
	std::string regola = "Assign 1 => Movement, 2 => HighRadiation, 3 => Warning Define Warning := {a1:stanza a1:is ?room . a1:radiazioni a1:is ?value . }From Movement := [select ?room ?bool where{?sensor a1:senstipo a1:MovSens; a1:haslocation ?room; a1:value ?bool.}] and each HighRadiation := [select ?sensor ?room ?value where{?sensor a1:senstipo a1:RadSens; a1:haslocation ?room; a1:value ?value. FILTER(?value > 150)}] within 600000 from Movement With Movement.?room = HighRadiation.?room Where (string)?room := Movement.?room, (int)?value := HighRadiation.?value ;";
	//std::ifstream infile;
	//infile.open("/home/dario/Scrivania/teslardf_rule.txt");
	//while(!infile.eof()){
	//	getline(infile, regola);
	//	std::cout << regola;
	//}
	//2)Query estratte da una regola RDFTesla
	//store->addQuery(parser.parseQueryType(1),parser.parseQueryName(1),parser.parseQueryString(1));
	//store->addQuery(parser.parseQueryType(2),parser.parseQueryName(2),parser.parseQueryString(2));
	parser.parse(regola, store, e, constructor);
	//3)Template evento complesso
	//constructor->addTemplate(3, parser.parseTemplateCE());

//Subscription
	Constraint c[1];
	strcpy(c[0].name, "value");
	c[0].type = INT;
	c[0].op = GT;
	c[0].intVal = 140;
	SubPkt *sub = new SubPkt(3, c, 1);
	RDFResultListener *listener = new TestRDFListener(sub);
	constructor->addRDFListener(listener);

/*Runtime: arrivano eventi al server (pubblicazioni da parte del client).
*	   1)materializzo in kb.
*	   2)valuto query.
*	   3)passo risultati al Result converter (lowering rule)
*	   4)eventi convertiti mandati in input a TRex
*	   5)TRex fa processing e manda risultati ai vari listener<---RDF Constructor che ricevendoli è incaricato di produrre il CE RDF come output
*/	
	const char* e1 = "./TestEvents/t1.ttl";
	const char* e11 = "./TestEvents/t2.ttl";
	const char* e2 = "./TestEvents/t3.ttl";
	const char* e3 = "./TestEvents/t4.ttl";
	const char* e4 = "./TestEvents/t6.ttl";
	const char* e5 = "./TestEvents/t7.ttl";
	const char* e6 = "./TestEvents/t8.ttl";
	
	std::cout << "--------------------Evento " << a << "-----------------------------" << "\n";
	processPubPkt(conv.convertToTesla(store->processRdfEvent(e1)), e);
	std::cout << "--------------------Evento " << a << "-----------------------------" << "\n";
	processPubPkt(conv.convertToTesla(store->processRdfEvent(e11)), e);
	std::cout << "--------------------Evento " << a << "-----------------------------" << "\n";
	processPubPkt(conv.convertToTesla(store->processRdfEvent(e2)), e);
	std::cout << "--------------------Evento " << a << "-----------------------------" << "\n";
	processPubPkt(conv.convertToTesla(store->processRdfEvent(e3)), e);
	std::cout << "--------------------Evento " << a << "-----------------------------" << "\n";
	processPubPkt(conv.convertToTesla(store->processRdfEvent(e4)), e);
	std::cout << "--------------------Evento " << a << "-----------------------------" << "\n";
	processPubPkt(conv.convertToTesla(store->processRdfEvent(e5)), e);
	std::cout << "--------------------Evento " << a << "-----------------------------" << "\n";
	processPubPkt(conv.convertToTesla(store->processRdfEvent(e6)), e);
	std::cout << "-------------------------------------------------------------------" << "\n";

	return 0;
}
