#pragma once

#include "ObjectBase.h"

class Level: public ObjectBase
{
public:
	int rowCount = 3;
	int columnCount = 20;
	int rowSpacing = 3;
	int coulmnSpacing = 3;

public:
	Level() : ObjectBase() {}
	Level(int rowCount, int columnCount, int rowSpacing, int columnSpacing, int width, int height, const char* texturePath):ObjectBase(width, height, texturePath)
	{
		this->rowCount = rowCount;
		this->columnCount = columnCount;
		this->rowSpacing = rowSpacing;
		this->coulmnSpacing = columnSpacing;
	}
	virtual ~Level(){}

	void ObjectBase::ObjectInfo() {}
};

