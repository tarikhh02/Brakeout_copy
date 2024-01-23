#include "UI.h"
#include <thread>

void UI::DisplayStartHUD(Game* game)
{
	if (!game->isInitializationFinished)
		return;

	game->renderer.ResetTextureFromLastPosition(game->renderer.bufferWidth / 2, 25, game->renderer.bufferWidth, 50, &game->level);

	std::thread([](Renderer* renderer, Game* game) 
		{ 
			std::string scoreTxt = "SCORE: " + std::to_string(game->player.highScore);
			
			if(UI::scoreUIPositionValues[0] != 0)
				renderer->ResetTextureFromLastPosition(110, renderer->bufferHeight - 25, UI::scoreUIPositionValues[0] + 10, UI::scoreUIPositionValues[1] + 10, &game->level);
			UI::ShowTextUI("SCORE: 0", 110, renderer->bufferHeight - 25, 200, 35, 3, UI::scoreUIPositionValues, 0x0f0f0f0f, renderer); 
		}, &game->renderer, game).detach();

	std::thread([](Renderer* renderer, int level) 
		{
			std::string textToShow = "LEVEL: " + std::to_string(level);
			UI::ShowTextUI(textToShow.c_str(), renderer->bufferWidth - 110, renderer->bufferHeight - 25, 200, 35, 3, nullptr, 0x0f0f0f0f, renderer);
		}, &game->renderer, game->currentLevel).detach();
}