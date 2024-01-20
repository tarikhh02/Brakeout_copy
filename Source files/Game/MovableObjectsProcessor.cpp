#include <thread>
#include "Game.h"

void Game::ProcessMovableObjects()
{
	if (!canAccessFunction || !isGameRunning)
		return;

	canAccessFunction = false;

	std::thread([](Game* game)
		{
			game->ProcessEachMovableObject(&game->player, &game->player.physicsVelocity, true);
		}, this).join();
			
	ProcessEachMovableObject(&ball, &ball.physicsVelocity, false);
		
	canAccessFunction = true;
}