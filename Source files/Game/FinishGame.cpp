#include "Game.h"

#include <thread>

void Game::FinishGame(const char* finishText)
{
	isGameFinished = true;

	ResetBallAndPlayer();

	std::thread([finishText](Renderer* renderer) 
		{
			UI::ShowTextUI(finishText, renderer->bufferWidth / 2, renderer->bufferHeight - 200, renderer->bufferWidth / 10, 3, UI::finishGameUIPositionValues, renderer);

			/*int txtLen = strlen(finishText);
			int size = (renderer->bufferWidth / 4 - (txtLen * 2)) / (txtLen * 6);

			UI::finishGameUIPositionValues[1] = size * 7;
			UI::finishGameUIPositionValues[0] = (txtLen * (6 * size + 2));

			renderer->DrawExpression(finishText, renderer->bufferWidth / 2 - UI::finishGameUIPositionValues[0] / 2, renderer->bufferHeight - 200, size ,2);*/
		}, &renderer).detach();

	std::thread([](Renderer* renderer, int highScore)
		{
			std::string scoreTxt = "SCORE: " + std::to_string(highScore);		

			UI::ShowTextUI(scoreTxt.c_str(), renderer->bufferWidth / 2, renderer->bufferHeight - 350, renderer->bufferWidth / 8, 3, UI::scoreUIPositionValues, renderer);

			/*int txtLen = scoreTxt.size();
			int size = (renderer->bufferWidth / 4 - (txtLen * 2)) / (txtLen * 6);

			UI::scoreUIPositionValues[1] = size * 7;
			UI::scoreUIPositionValues[0] = (txtLen * (6 * size + 2));

			renderer->DrawExpression(scoreTxt.c_str(), renderer->bufferWidth / 2 - UI::scoreUIPositionValues[0] / 2, renderer->bufferHeight - 350, size, 2);*/
		}, &renderer, player.highScore).detach();

	ResetBricks();

	player.highScore = 0;
}