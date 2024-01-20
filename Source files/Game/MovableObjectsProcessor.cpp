#include <thread>
#include "Game.h"

void Game::ProcessMovableObjects()
{
	if (!canAccessFunction || !isGameRunning)
		return;

	ProcessEachMovableObject(&player, &player.physicsVelocity, true);
	ProcessEachMovableObject(&ball, &ball.physicsVelocity, false); 
}