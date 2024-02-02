#include "Physics.h"

void Physics::MoveObject(MovableObject* object, float deltaTime, int maxX, bool isPlayer)
{
	int newXPos = object->xPos;
	int newYPos = object->yPos;
	
	float directionModifierValue = 1;

	if(object->physicsVelocity.xDirection != 0 && object->physicsVelocity.yDirection != 0)
		directionModifierValue = CalculateAngleModifier(object->physicsVelocity.xDirection, object->physicsVelocity.yDirection);

	float newXPosPrecentage = (object->physicsVelocity.xDirection * directionModifierValue * object->physicsVelocity.velocity) * deltaTime;
	float newYPosPrecentage = (object->physicsVelocity.yDirection * directionModifierValue * object->physicsVelocity.velocity) * deltaTime;

	newXPos += (int)newXPosPrecentage;
	newYPos += (int)newYPosPrecentage;

	if (isPlayer)
	{
		if (newXPos + object->width / 2 > maxX)
			newXPos = maxX - object->width / 2;
		else if (newXPos - object->width / 2 < 0)
			newXPos = object->width / 2;
	}

	object->SetUpNewPosition(newXPos, newYPos);
}