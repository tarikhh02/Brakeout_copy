#pragma once

#include "ObjectBase.h"
#include "PhysicsVelocity.h"

class Collider
{
public:
	static enum CollisionType
	{
		DIE_COLLISION,
		NO_COLLISION,
		BASIC_COLLISION,
		SIDE_COLLISION,
		CORNER_COLLISION,
		PLAYER_COLLISION,
	};

public:
	static CollisionType HandleCollisions(ObjectBase* objectThatCollides, PhysicsVelocity* objectPhysicsVelocityComponent, ObjectBase* objectWithWhichCollidesWith);
	static CollisionType HandleWallCollisions(ObjectBase* objectThatCollides, int bufferWidth, int bufferHeight);

private:
	static bool CheckAxis(int x, int y, int xConstraint1, int xConstraint2, int yConstraint1, int yConstraint2);
};