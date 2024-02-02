#pragma once

#include "ObjectBase.h"
#include "PhysicsVelocity.h"

class MovableObject : public ObjectBase
{
public:
	int highScore = 0;
	int livesNumber = 3;
	bool hasWon = false;
	bool isAlive = true;
	bool isInitialized = false;
	PhysicsVelocity physicsVelocity;

public:
	MovableObject(){}
	MovableObject(int width, int height, const char* texturePath) : ObjectBase(width, height, texturePath)
	{
		physicsVelocity = PhysicsVelocity(0, 0, 1200);
	}
	virtual ~MovableObject(){}

	void ObjectBase::ObjectInfo(){}
};

