#include "Game.h"

void Game::ProcessMovableObjects()
{
	if (!canAccessFunction || !isGameRunning || !hasNextLevelLoaded)
		return;

	movementDeltaTimeHolder += deltaTime;

	ProcessEachMovableObject(&ball, false, movementDeltaTimeHolder);

	ProcessEachMovableObject(&player, true, movementDeltaTimeHolder);

	if (movementDeltaTimeHolder > 0.0025)
		movementDeltaTimeHolder = 0;
}