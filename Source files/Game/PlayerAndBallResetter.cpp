#include "Game.h"
#include "UI.h"

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

	std::thread([](Renderer* renderer, bool hasPlayerWon) 
		{ 
			const char* textToShow = nullptr;

			if (hasPlayerWon)
				textToShow = "PRESS SPACE TO CONTINUE";
			else
				textToShow = "PRESS SPACE TO START";

			UI::ShowTextUI(textToShow, renderer->bufferWidth / 2, 200, renderer->bufferWidth / 3, 35, 3, UI::startUIPositionValues, 0x0f0f0f0f, renderer);
		}, &renderer, player.hasWon).detach();

	std::thread([](Renderer* renderer, Level* level, int index)
		{
			renderer->ResetTextureFromLastPosition(renderer->bufferWidth / 2, renderer->bufferHeight - 25, UI::heartsUIPositionValues[0] + 10, UI::heartsUIPositionValues[1] + 10, level);
			if (index < 0)
				index = 2;
			UI::ShowTextUI(UI::playerLivesToTxt[index], renderer->bufferWidth / 2, renderer->bufferHeight - 25, (index + 1) * 60, 35, 3, UI::heartsUIPositionValues, 0xff0000, renderer);
		}, &renderer, &level, player.livesNumber - 1).detach();
}