#include "Game.h"

void Game::StartGame()
{
	if (isGameFinished)
		player.livesNumber = 3;
	isGameFinished = false;
	player.isAlive = true;
	ball.physicsVelocity.SetDirection(0, -1);
}