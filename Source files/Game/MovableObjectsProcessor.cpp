#include <thread>
#include "Game.h"

void Game::ProcessMovableObjects()
{
	if (!canAccessFunction || columnsInitialized < level.columnCount)
		return;

	canAccessFunction = false;

	std::thread([](Game* game)
		{
			game->ProcessEachMovableObject(&game->player, &game->player.physicsVelocity, true);
		}, this).detach();
			
	std::thread([](Game* game)
		{
			game->ProcessEachMovableObject(&game->ball, &game->ball.physicsVelocity, false);
		}, this).detach();
		
	canAccessFunction = true;
}