#include "Physics.h"

void Physics::SetUpDirectionAfterCornerContact(PhysicsVelocity* physicsVelocityComponent, float xCornerDirection, float yCornerDirection)
{
	physicsVelocityComponent->SetDirection(xCornerDirection / 2, yCornerDirection / 2);
}