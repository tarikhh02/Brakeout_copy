#include <thread>
#include "Game.h"

void Game::ProcessMovableObjects()
{
	if (!canAccessFunction || !isGameRunning)
		return;

	canAccessFunction = false;

	ProcessEachMovableObject(&player, &player.physicsVelocity, true);
			
	std::thread([](Game* game)
		{
			game->ProcessEachMovableObject(&game->ball, &game->ball.physicsVelocity, false);
		}, this).detach();
	
	canAccessFunction = true;
}