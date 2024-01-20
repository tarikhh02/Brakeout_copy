#include "Game.h"

void Game::ResetBallAndPlayer() 
{
	renderer.ResetTextureFromLastPosition(ball.xPos, ball.yPos, ball.width, ball.height, &level);
	ball.SetUpNewPosition(renderer.bufferWidth / 2, renderer.bufferHeight / 2);
	ball.physicsVelocity.SetDirection(0, 0);

	renderer.ResetTextureFromLastPosition(player.xPos, player.yPos, player.width, player.height, &level);
	player.SetUpNewPosition(renderer.bufferWidth / 2, player.height);
	player.isAlive = false;
}