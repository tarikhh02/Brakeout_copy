#include "Game.h"

bool Game::ProcessBallCollisionsWithPlayer()
{
	Collider::CollisionType collisionType;

	collisionType = Collider::HandleCollisions(&ball, &player);

	if (collisionType != Collider::NO_COLLISION)
	{
		if (collisionType == Collider::SIDE_COLLISION)
			Physics::SetUpDirectionAfterBasicContact(collisionType, &ball.physicsVelocity, 0);
		else if (collisionType == Collider::BASIC_COLLISION)
			Physics::SetUpDirectionAfterBasicContact(Collider::PLAYER_COLLISION, &ball.physicsVelocity, player.physicsVelocity.xDirection);
		
		return true;
	}

	return false;
}