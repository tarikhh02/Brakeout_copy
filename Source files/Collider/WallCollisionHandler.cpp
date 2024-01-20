#include "Collider.h"

Collider::CollisionType Collider::HandleWallCollisions(ObjectBase* objectThatCollides, int bufferWidth, int bufferHeight)
{
	if (objectThatCollides->xPos + objectThatCollides->width / 2 >= bufferWidth || objectThatCollides->xPos - objectThatCollides->width / 2 <= 0)
		return SIDE_COLLISION;

	else if (objectThatCollides->yPos + objectThatCollides->height / 2 >= bufferHeight)
		return BASIC_COLLISION;

	else if (objectThatCollides->yPos - objectThatCollides->height / 2 <= 0)
		return DIE_COLLISION;

	return NO_COLLISION;
}