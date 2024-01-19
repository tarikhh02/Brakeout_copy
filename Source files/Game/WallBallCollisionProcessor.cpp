#include "Game.h"

void Game::ProcessBallCollisionsWithWalls()
{
	Collider::CollisionType collisionType = Collider::HandleWallCollisions(&ball, renderer.bufferWidth, renderer.bufferHeight);

	if (collisionType == Collider::DIE_COLLISION)
	{
		float startSpeed = -1;

		player.livesNumber--;

		if (player.livesNumber <= 0)
			startSpeed = 0;

		ball.SetUpNewPosition(renderer.bufferWidth / 2, renderer.bufferHeight / 2);
		ball.physicsVelocity.SetDirection(0, startSpeed);

		return;
	}

	if(collisionType != Collider::NO_COLLISION)
		Physics::SetUpDirectionAfterBasicContact(collisionType, &ball.physicsVelocity, 0);
}