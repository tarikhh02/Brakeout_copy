#include "Game.h"

void Game::StartGame()
{
	std::thread([](Renderer* renderer, Level* level) 
		{
			renderer->ResetTextureFromLastPosition(renderer->bufferWidth / 2, 190, UI::startUIPositionValues[0] + 50, UI::startUIPositionValues[1] + 50, level);
		}, &renderer, &level).detach();

	std::thread([](Renderer* renderer, Level* level)
		{
			renderer->ResetTextureFromLastPosition(renderer->bufferWidth / 2, renderer->bufferHeight - 200, UI::finishGameUIPositionValues[0] + 50, UI::finishGameUIPositionValues[1] + 50, level);
		}, &renderer, &level).detach();

	//std::thread([](Renderer* renderer, Level* level)
	//	{
	//		renderer->ResetTextureFromLastPosition(renderer->bufferWidth / 2, renderer->bufferHeight - 350, UI::scoreUIPositionValues[0] + 50, UI::scoreUIPositionValues[1] + 50, level);
	//	}, &renderer, &level).detach();

	if (isGameFinished)
		player.livesNumber = 3;
	isGameFinished = false;
	player.isAlive = true;
	ball.physicsVelocity.SetDirection(0, -1);
}