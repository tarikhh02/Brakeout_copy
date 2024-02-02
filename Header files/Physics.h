#pragma once

#include "MovableObject.h"
#include "PhysicsVelocity.h"
#include "Collider.h"

class Physics
{
public:
	static void MoveObject(MovableObject* object, float deltaTime, int maxX, bool isPlayer);
	static void SetUpDirectionAfterBasicContact(Collider::CollisionType collisionType, PhysicsVelocity* physicsVelocity, float directionModifier);
	static void SetUpDirectionAfterCornerContact(PhysicsVelocity* physicsVelocityComponent, float xCornerDirection, float yCornerDirection);

private:
	static float* GetOppositeAngleDirection(float xDirection, float yDirection, Collider::CollisionType collisionType);
	static float CalculateAngleModifier(float xDirection, float yDirection);
	static void CheckAndProcessStraightDirections(float& zeroValue, float zeroValueConstraint, float& oneValue, float oneValueConstraint, int playerDirection);
};