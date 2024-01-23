#include "Game.h"
#include "UI.h"
#include <chrono>

void Game::LoadNextLevel()
{
	std::thread([](Game* game)
		{
			if (!game->hasNextLevelLoaded)
				return;

			game->hasNextLevelLoaded = false;

			std::this_thread::sleep_for(std::chrono::seconds(1));
			game->InitializeObjects();
			game->AdaptGameForNewScreenSize(game->hWnd);
			UI::DisplayStartHUD(game);
			game->ResetBallAndPlayer();

			game->player.hasWon = false;
			game->hasNextLevelLoaded = true;
		}, this).detach();
}