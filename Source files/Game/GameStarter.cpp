#include "Game.h"
#include "UI.h"

void Game::StartGame()
{
	std::thread([](Renderer* renderer, Level* level) 
		{
			renderer->ResetTextureFromLastPosition(renderer->bufferWidth / 2, 200, UI::startUIPositionValues[0] + 10, UI::startUIPositionValues[1] + 10, level);
		}, &renderer, &level).detach();

	std::thread([](Renderer* renderer, Level* level)
		{
			renderer->ResetTextureFromLastPosition(renderer->bufferWidth / 2, renderer->bufferHeight - 200, UI::finishGameUIPositionValues[0] + 10, UI::finishGameUIPositionValues[1] + 10, level);
		}, &renderer, &level).detach();

	std::thread([](Renderer* renderer, Level* level, int playerHighScsore)
		{
			std::string scoreTxt = "SCORE: " + std::to_string(playerHighScsore);

			renderer->ResetTextureFromLastPosition(110, renderer->bufferHeight - 25, UI::scoreUIPositionValues[0] + 10, UI::scoreUIPositionValues[1] + 10, level);
			UI::ShowTextUI(scoreTxt.c_str(), 110, renderer->bufferHeight - 25, 200, 35, 3, UI::scoreUIPositionValues, 0x0f0f0f0f, renderer);
		}, &renderer, &level, player.highScore).detach();

	if (isGameFinished && player.highScore == 0)
		player.livesNumber = 3;
	isGameFinished = false;
	player.isAlive = true;
	ball.physicsVelocity.SetDirection(0, -1);
}