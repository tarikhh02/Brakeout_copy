#include "Game.h"
#include "UI.h"

#include <thread>

void Game::FinishGame(const char* finishText)
{
	isGameFinished = true;

	ResetBallAndPlayer();

	std::thread([finishText](Renderer* renderer)
		{
			UI::ShowTextUI(finishText, renderer->bufferWidth / 2, renderer->bufferHeight - 200, renderer->bufferWidth / 10, 35, 3, UI::finishGameUIPositionValues, 0x0f0f0f0f, renderer);
		}, &renderer).detach();

	if (!player.hasWon)
	{
		ResetBricks();
		player.highScore = 0;
	}
}