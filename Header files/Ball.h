#pragma once

#include <malloc.h>
#include "ObjectBase.h"
#include "PhysicsVelocity.h"

class Ball : public ObjectBase 
{
public:
	PhysicsVelocity physicsVelocity;

public:
	Ball(){}
	Ball(int width, int height, const char* texturePath) : ObjectBase(width, height, texturePath)
	{
		physicsVelocity = PhysicsVelocity(0, 0, 1000);
	}
	~Ball()
	{
		if (imageDecoded)
			free(imageDecoded);
	}

	void ObjectBase::ObjectInfo() {}
};