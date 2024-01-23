#pragma once

#include "ObjectBase.h"

class BrickType : public ObjectBase
{
public:
	char id = ' ';
	int hitPoints = 0;
	int hitPointsHolderValue = 0;
	const char* hitSoundPath = "";
	const char* breakSoundPath = "";
	bool isDestroyed = false;
	int brickBreakScore = 0;

public:
	BrickType() : ObjectBase(){}
	BrickType(char id, int width, int height, int hitPoints, const char* texturePath, const char* breakSoundPath, const char* hitSoundPath, int brickBreakScore) : ObjectBase(width, height, texturePath)
	{
		this->id = id;
		this->hitPoints = hitPoints;
		this->hitSoundPath = hitSoundPath;
		this->breakSoundPath = breakSoundPath;
		this->brickBreakScore = brickBreakScore;
		hitPointsHolderValue = hitPoints;
	}
	virtual ~BrickType(){}

	void ObjectBase::ObjectInfo() {}
};

