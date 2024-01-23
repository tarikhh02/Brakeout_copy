#include "Game.h"

bool Game::ProcessBallCollisionsWithWalls()
{
	Collider::CollisionType collisionType = Collider::HandleWallCollisions(&ball, renderer.bufferWidth, renderer.bufferHeight);

	if (collisionType == Collider::DIE_COLLISION)
	{
		player.livesNumber--;

		if (player.livesNumber <= 0)
			FinishGame("YOU LOST");

		ResetBallAndPlayer();

		return true;
	}

	if (collisionType != Collider::NO_COLLISION)
	{
		Physics::SetUpDirectionAfterBasicContact(collisionType, &ball.physicsVelocity, 0);
		return true;
	}

	return false;
}