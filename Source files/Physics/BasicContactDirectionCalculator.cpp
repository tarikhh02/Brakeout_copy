#include "Physics.h"
#include "Collider.h"

void Physics::SetUpDirectionAfterBasicContact(Collider::CollisionType collisionType, PhysicsVelocity* physicsVelocity, float directionModifier)
{
	float* oppositeAngleValues = GetOppositeAngleDirection(physicsVelocity->xDirection, physicsVelocity->yDirection, collisionType);

	float modifyingValue = 0.1f;

	if ((directionModifier > 0 && physicsVelocity->xDirection > 0)
		|| (directionModifier < 0 && physicsVelocity->xDirection < 0))
	{
		oppositeAngleValues[1] -= modifyingValue;
	}
	else if ((directionModifier > 0 && physicsVelocity->xDirection < 0)
		|| (directionModifier < 0 && physicsVelocity->xDirection > 0))
	{
		oppositeAngleValues[0] += directionModifier * modifyingValue;
	}

	if (collisionType == Collider::PLAYER_COLLISION)
	{
		CheckAndProcessStraightDirections(oppositeAngleValues[0], 0.1, oppositeAngleValues[1], 1, directionModifier);

		CheckAndProcessStraightDirections(oppositeAngleValues[1], 0.2, oppositeAngleValues[0], 1, 1);
	}

	physicsVelocity->SetDirection(oppositeAngleValues[0], oppositeAngleValues[1]);

	delete[] oppositeAngleValues;
}