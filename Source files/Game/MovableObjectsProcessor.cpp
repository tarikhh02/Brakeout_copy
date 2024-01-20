#include <thread>
#include "Game.h"

void Game::ProcessMovableObjects()
{
	if (!canAccessFunction || !isGameRunning)
		return;

	canAccessFunction = false;

	std::thread([](Game* game) { game->ProcessEachMovableObject(&game->player, &game->player.physicsVelocity, true); }, this).detach();

	std::thread([](Game* game, bool* canAccessFunction) 
		{ 
			game->ProcessEachMovableObject(&game->ball, &game->ball.physicsVelocity, false); 
			*canAccessFunction = true; 
		}, this, &canAccessFunction).detach();

	//canAccessFunction = true;
}