#include "Collider.h"

Collider::CollisionType Collider::HandleWallCollisions(ObjectBase* objectThatCollides, int bufferWidth, int bufferHeight)
{
	int offset = 2;

	if (objectThatCollides->xPos + objectThatCollides->width / 2 >= bufferWidth)
	{
		objectThatCollides->xPos = bufferWidth - objectThatCollides->width / 2 - offset;
		return SIDE_COLLISION;
	}
	else if (objectThatCollides->xPos - objectThatCollides->width / 2 <= 0)
	{
		objectThatCollides->xPos = objectThatCollides->width / 2 + offset;
		return SIDE_COLLISION;
	}
	else if (objectThatCollides->yPos + objectThatCollides->height / 2 >= bufferHeight - 60)
	{
		objectThatCollides->yPos = bufferHeight - 60 - objectThatCollides->height / 2 - offset;
		return BASIC_COLLISION;
	}
	else if (objectThatCollides->yPos - objectThatCollides->height / 2 <= 0)
	{
		objectThatCollides->yPos = objectThatCollides->height / 2 + offset;
		return DIE_COLLISION;
	}

	return NO_COLLISION;
}