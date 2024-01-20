#pragma once

#include "ObjectBase.h"
#include "PhysicsVelocity.h"

class Player : public ObjectBase
{
public:
	int livesNumber = 3;
	bool isAlive = true;
	PhysicsVelocity physicsVelocity;

public:
	Player(){}
	Player(int width, int height, const char* texturePath) : ObjectBase(width, height, texturePath)
	{
		physicsVelocity = PhysicsVelocity(0, 0, 1500);
	}
	~Player()
	{
		if (imageDecoded)
			free(imageDecoded);
	}

	void ObjectBase::ObjectInfo(){}
};

