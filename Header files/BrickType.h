#pragma once

#include "ObjectBase.h"

class BrickType : public ObjectBase
{
public:
	char id = ' ';
	int hitPoints = 0;
	const char* hitSoundPath = "";
	const char* breakSoundPath = "";

public:
	BrickType() : ObjectBase(){}
	BrickType(char id, int width, int height, int hitPoints, const char* texturePath, const char* breakSoundPath, const char* hitSoundPath) : ObjectBase(width, height, texturePath)
	{
		this->id = id;
		this->hitPoints = hitPoints;
		this->hitSoundPath = hitSoundPath;
		this->breakSoundPath = breakSoundPath;
	}

	void ObjectBase::ObjectInfo() {}
};

