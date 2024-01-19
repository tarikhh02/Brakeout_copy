#include "Physics.h"

float* Physics::GetOppositeAngleDirection(float x, float y, Collider::CollisionType collisionType)
{
	if (collisionType == Collider::SIDE_COLLISION)
	{
		x = -x;
		y = -y;
	}

	float* oppositeAngleValues = new float[2];

	oppositeAngleValues[0] = x;
	oppositeAngleValues[1] = -y;

	return oppositeAngleValues;
}