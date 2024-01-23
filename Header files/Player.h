#pragma once

#include "ObjectBase.h"
#include "PhysicsVelocity.h"

class Player : public ObjectBase
{
public:
	int highScore = 0;
	int livesNumber = 3;
	bool hasWon = false;
	bool isAlive = true;
	PhysicsVelocity physicsVelocity;

public:
	Player(){}
	Player(int width, int height, const char* texturePath) : ObjectBase(width, height, texturePath)
	{
		physicsVelocity = PhysicsVelocity(0, 0, 1000);
	}
	~Player(){}

	void ObjectBase::ObjectInfo(){}
};

