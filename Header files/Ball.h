#pragma once

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
		physicsVelocity = PhysicsVelocity(0, 0, 1200);
	}
	virtual ~Ball(){}

	void ObjectBase::ObjectInfo() {}
};