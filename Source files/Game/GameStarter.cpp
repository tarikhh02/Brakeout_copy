#include "Game.h"

void Game::StartGame()
{
	isGameFinished = false;
	player.isAlive = true;
	ball.physicsVelocity.SetDirection(0, -1);
}