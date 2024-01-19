#include "Game.h"

void Game::ProcessCollisions()
{
	bool didCollide = ProcessBallCollisionsWithBricks();

	if (ball.physicsVelocity.yDirection < 0 && !didCollide)
		didCollide = ProcessBallCollisionsWithPlayer();

	if (!didCollide)
		ProcessBallCollisionsWithWalls();
}