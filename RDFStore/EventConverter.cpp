#include "EventConverter.h"

/*typedef uint8_t DatatypeID;
const DatatypeID D_INVALID_DATATYPE_ID = 0;
const DatatypeID D_IRI_REFERENCE = 1;
const DatatypeID D_BLANK_NODE = 2;
const DatatypeID D_XSD_STRING = 3;
const DatatypeID D_RDF_PLAIN_LITERAL = 4;
const DatatypeID D_XSD_INTEGER = 5;
const DatatypeID D_XSD_FLOAT = 6;
const DatatypeID D_XSD_DOUBLE = 7;
const DatatypeID D_XSD_BOOLEAN = 8;
const DatatypeID D_XSD_DATE_TIME = 9;
const DatatypeID D_XSD_TIME = 10;
const DatatypeID D_XSD_DATE = 11;
const DatatypeID D_XSD_G_YEAR_MONTH = 12;
const DatatypeID D_XSD_G_YEAR = 13;
const DatatypeID D_XSD_G_MONTH_DAY = 14;
const DatatypeID D_XSD_G_DAY = 15;
const DatatypeID D_XSD_G_MONTH = 16;
const DatatypeID D_XSD_DURATION = 17;*/

/*enum ValType {
	INT=0,
	FLOAT=1,
	BOOL=2,
	STRING=3
};*/

void shrinkIRI(char* lexicalForm, const char** prefixesArray, int prefixesLength){
	std::string string(lexicalForm);
	size_t found;
	for(int i = 0; i < prefixesLength; i = i+2){
		std::string prefix(*(prefixesArray+i+1));
		found = string.find(prefix);
		if(found == 0){//prefisso trovato, lo scambio
			string.replace(string.begin(), string.begin()+ prefix.size(), *(prefixesArray+i));
			strcpy(lexicalForm, string.c_str());
			break;
		}
	}
}

/**
*  See RDFox: Common.h for datatypeID
*      TRex: Const.h for ValType
**/
void defineAttFromType(Attribute* att, Resource* res, Event* event){
	switch(res->datatypeID){
		case 1://IRI
			att->type = STRING;
			shrinkIRI(res->lexicalForm, RDFStore::getInstance()->getPrefixesArray(), RDFStore::getInstance()->getPrefixesArrayLength());//cambio IRI col suo prefisso
			strcpy(att->stringVal, res->lexicalForm);
			break;
		case 5://INT
			att->type = INT;
			att->intVal = atoi(res->lexicalForm);
			break;
		case 6://FLOAT
			att->type = FLOAT;
			att->floatVal = (float)atof(res->lexicalForm);
			break;
		case 7://DOUBLE, loses precision
			att->type = FLOAT;
			att->floatVal = (float)atof(res->lexicalForm);
			break;
		case 8://BOOL
			att->type = BOOL;
			if(strcmp(res->lexicalForm, "true") == 0){
				att->boolVal = true;
			}else{
				att->boolVal = false;
			}
			break;
		default:
			att->type = STRING;
			strcpy(att->stringVal, res->lexicalForm);
			break;
	}
}

/**
*  Converts RdfEvent into TeslaEvent and frees memory about RdfEvent
**/
std::vector<PubPkt*> EventConverter::convertToTesla(std::vector<Event*> events){
	std::vector<PubPkt*> pubPkts;
	for(std::vector<Event*>::iterator event = events.begin() ; event != events.end(); event++){
		int num = (*event)->attributes.size();
		Attribute tempAtt[num];
		int i = 0;
		for(std::map<const char*, Resource*>::iterator res = (*event)->attributes.begin(); res != (*event)->attributes.end(); res++){
			strcpy(tempAtt[i].name, res->first);
			defineAttFromType(tempAtt+i, res->second, *event);
			delete[] res->second->lexicalForm;
			delete res->second;//una volta copiato come attributo, libero memoria
			i++;
		}   
		PubPkt* temp= new PubPkt((*event)->eventType, tempAtt, num);
		pubPkts.push_back(temp);
		delete *event;//svuoto il vettore degli eventi, perchè ormai l'evento l'ho convertito in TeslaEvent
	}
	return pubPkts;	
}
