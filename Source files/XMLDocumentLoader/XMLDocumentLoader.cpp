#include "XMLDocumentLoader.h"

pugi::xml_document XMLDocumentLoader::xmlDocument = pugi::xml_document();

bool XMLDocumentLoader::LoadXMLFile(const char* xmlDocumentPath)
{
    pugi::xml_parse_result result = xmlDocument.load_file(xmlDocumentPath);

    if (result) 
        return true;

    return false;
}