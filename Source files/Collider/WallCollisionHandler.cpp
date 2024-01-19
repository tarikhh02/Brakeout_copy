#include "Collider.h"

Collider::CollisionType Collider::HandleWallCollisions(ObjectBase* objectThatCollides, int bufferWidth, int bufferHeight)
{
	if (objectThatCollides->xPos + objectThatCollides->width / 2 >= bufferWidth - 1 || objectThatCollides->xPos - objectThatCollides->width / 2 <= 1)
		return SIDE_COLLISION;

	if (objectThatCollides->yPos + objectThatCollides->height / 2 >= bufferHeight - 1)
		return BASIC_COLLISION;

	if (objectThatCollides->yPos - objectThatCollides->height / 2 <= 1)
		return DIE_COLLISION;

	return NO_COLLISION;
}