#include "Game.h"

void Game::ResetBallAndPlayer()
{
	if (!isInitializationFinished)
		return;

	renderer.ResetTextureFromLastPosition(ball.xPos, ball.yPos, ball.width, ball.height, &level);
	ball.SetUpNewPosition(renderer.bufferWidth / 2, renderer.bufferHeight / 2);
	ball.physicsVelocity.SetDirection(0, 0);

	renderer.ResetTextureFromLastPosition(player.xPos, player.yPos, player.width, player.height, &level);
	player.SetUpNewPosition(renderer.bufferWidth / 2, player.height);
	player.isAlive = false;

	std::thread([](Renderer* renderer) 
		{ 
			UI::ShowTextUI("PRESS SPACE TO START", renderer->bufferWidth / 2, 200, renderer->bufferWidth / 3, 35, 3, UI::startUIPositionValues, renderer);
		}, &renderer).detach();
}