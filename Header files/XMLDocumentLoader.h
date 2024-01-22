#pragma once

#include "PUGIXML/pugixml.hpp"

class XMLDocumentLoader
{
public:
	static pugi::xml_document xmlDocument;

public:
	static bool LoadXMLFile(const char* xmlDocumentPath);
};