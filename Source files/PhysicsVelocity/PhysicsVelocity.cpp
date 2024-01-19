#include "PhysicsVelocity.h"

void PhysicsVelocity::SetDirection(float xDirection, float yDirection)
{
	this->xDirection = xDirection;
	this->yDirection = yDirection;
}

void PhysicsVelocity::SetVelocity(float velocity)
{
	this->velocity = velocity;
}