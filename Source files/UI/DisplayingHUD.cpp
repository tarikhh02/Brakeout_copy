#include "UI.h"
#include <thread>

void UI::DisplayStartHUD(Game* game)
{
	if (!game->isInitializationFinished)
		return;

	game->renderer.ResetTextureFromLastPosition(game->renderer.bufferWidth / 2, 25, game->renderer.bufferWidth, 50, &game->level);

	std::thread([](Renderer* renderer) 
		{ 
			UI::ShowTextUI("SCORE: 0", 110, renderer->bufferHeight - 25, 200, 35, 3, UI::scoreUIPositionValues, 0x0f0f0f0f, renderer); 
		}, &game->renderer).detach();

	std::thread([](Renderer* renderer, int level) 
		{
			std::string textToShow = "LEVEL: " + std::to_string(level);
			UI::ShowTextUI(textToShow.c_str(), renderer->bufferWidth - 110, renderer->bufferHeight - 25, 200, 35, 3, nullptr, 0x0f0f0f0f, renderer);
		}, &game->renderer, game->currentLevel).detach();
}