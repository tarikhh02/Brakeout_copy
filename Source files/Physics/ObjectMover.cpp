#include "Physics.h"

void Physics::MoveObject(ObjectBase* object, PhysicsVelocity* physicsVelocityComponent, float deltaTime, int maxX, int maxY)
{
	int newXPos = object->xPos;
	int newYPos = object->yPos;

	float newXPosPrecentage = physicsVelocityComponent->xDirection * physicsVelocityComponent->velocity * deltaTime;
	float newYPosPrecentage = physicsVelocityComponent->yDirection * physicsVelocityComponent->velocity * deltaTime;

	newXPos += (int)(newXPosPrecentage * maxX);
	newYPos += (int)(newYPosPrecentage * maxY);

	if (newXPos + object->width / 2 > maxX)
		newXPos = maxX - object->width / 2;
	else if(newXPos - object->width / 2 < 0)
		newXPos = object->width / 2;

	if (newYPos + object->height / 2 > maxY)
		newYPos = maxY - object->height / 2;
	else if(newYPos - object->height / 2 < 0)
		newYPos = object->height / 2;

	object->SetUpNewPosition(newXPos, newYPos);
}