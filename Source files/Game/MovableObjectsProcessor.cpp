#include "Game.h"

void Game::ProcessMovableObjects()
{
	if (!canAccessFunction || !isGameRunning || !hasNextLevelLoaded)
		return;

	canAccessFunction = false;

	movementDeltaTimeHolder += deltaTime;

	std::thread([](Game* game, float movementDeltaTimeHolder)
		{
			game->ProcessEachMovableObject(&game->ball, &game->ball.physicsVelocity, false, movementDeltaTimeHolder);

		}, this, movementDeltaTimeHolder).detach();

	std::thread([](Game* game, float movementDeltaTimeHolder, bool* canAccessFunction)
		{
			game->ProcessEachMovableObject(&game->player, &game->player.physicsVelocity, true, movementDeltaTimeHolder);

			*canAccessFunction = true;

		}, this, movementDeltaTimeHolder, &canAccessFunction).detach();

		if (movementDeltaTimeHolder > 0.0025)
			movementDeltaTimeHolder = 0;
}