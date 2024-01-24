#pragma once

#include "ObjectBase.h"
#include "PhysicsVelocity.h"
#include "Collider.h"

class Physics
{
public:
	static void MoveObject(ObjectBase* object, PhysicsVelocity* physicsVelocityComponent, float deltaTime, int maxX, bool isPlayer);
	static void SetUpDirectionAfterBasicContact(Collider::CollisionType collisionType, PhysicsVelocity* physicsVelocity, float directionModifier);
	static void SetUpDirectionAfterCornerContact(PhysicsVelocity* physicsVelocity, float xCornerDirection, float yCornerDirection);

private:
	static float* GetOppositeAngleDirection(float xDirection, float yDirection, Collider::CollisionType collisionType);
	static float CalculateAngleModifier(float xDirection, float yDirection);
	static void CheckAndProcessStraightDirections(float& zeroValue, float zeroValueConstraint, float& oneValue, float oneValueConstraint, int playerDirection);
};