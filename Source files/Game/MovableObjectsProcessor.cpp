#include "Game.h"

void Game::ProcessMovableObjects()
{
	if (!canAccessFunction || !isGameRunning || !hasNextLevelLoaded)
		return;

	movementDeltaTimeHolder += deltaTime;

	ProcessEachMovableObject(&ball, &ball.physicsVelocity, false, movementDeltaTimeHolder);

	ProcessEachMovableObject(&player, &player.physicsVelocity, true, movementDeltaTimeHolder);

	if (movementDeltaTimeHolder > 0.0025)
		movementDeltaTimeHolder = 0;
}