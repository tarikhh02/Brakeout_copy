#include "Physics.h"
#include "Collider.h"

void Physics::SetUpDirectionAfterBasicContact(Collider::CollisionType collisionType, PhysicsVelocity* physicsVelocity, float directionModifier)
{
	float* oppositeAngleValues = GetOppositeAngleDirection(physicsVelocity->xDirection, physicsVelocity->yDirection, collisionType);

	float modifyingValue = 0.20f;

	if ((directionModifier > 0 && physicsVelocity->xDirection > 0)
		|| (directionModifier < 0 && physicsVelocity->xDirection < 0))
	{
		if (oppositeAngleValues[0] > 0)
		{
			oppositeAngleValues[0] += modifyingValue;
			oppositeAngleValues[1] -= modifyingValue;
		}
		else if (oppositeAngleValues[0] < 0)
		{
			oppositeAngleValues[0] -= modifyingValue;
			oppositeAngleValues[1] -= modifyingValue;
		}
	}
	else if ((directionModifier > 0 && physicsVelocity->xDirection < 0)
		|| (directionModifier < 0 && physicsVelocity->xDirection > 0))
	{
		if (oppositeAngleValues[0] > 0)
		{
			oppositeAngleValues[0] -= modifyingValue;
			oppositeAngleValues[1] += modifyingValue;
		}
		else if (oppositeAngleValues[0] < 0)
		{
			oppositeAngleValues[0] += modifyingValue;
			oppositeAngleValues[1] += modifyingValue;
		}
	}

	if (collisionType == Collider::PLAYER_COLLISION)
	{
		if (oppositeAngleValues[0] >= -0.1 && oppositeAngleValues[0] <= 0.1)
		{
			oppositeAngleValues[0] = 0.25f;
			oppositeAngleValues[1] = 0.75f;
		}
		else if (oppositeAngleValues[1] >= -0.1 && oppositeAngleValues[1] <= 0.1)
		{
			oppositeAngleValues[0] = 0.75f;
			oppositeAngleValues[1] = 0.25f;
		}
	}

	physicsVelocity->SetDirection(oppositeAngleValues[0], oppositeAngleValues[1]);

	delete[] oppositeAngleValues;
}