#include "Game.h"

#include <thread>

void Game::FinishGame(const char* finishText)
{
	isGameFinished = true;

	ResetBallAndPlayer();

	std::thread([finishText](Renderer* renderer) 
		{
			UI::ShowTextUI(finishText, renderer->bufferWidth / 2, renderer->bufferHeight - 200, renderer->bufferWidth / 10, 3, UI::finishGameUIPositionValues, renderer);
		}, &renderer).detach();

	/*std::thread([](Renderer* renderer, int highScore)
		{
			std::string scoreTxt = "SCORE: " + std::to_string(highScore);		

			UI::ShowTextUI(scoreTxt.c_str(), renderer->bufferWidth / 2, renderer->bufferHeight - 350, renderer->bufferWidth / 8, 3, UI::scoreUIPositionValues, renderer);
		}, &renderer, player.highScore).detach();*/

	ResetBricks();

	player.highScore = 0;
}