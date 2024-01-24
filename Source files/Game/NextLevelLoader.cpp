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

			game->InitializeObjects();
			game->AdaptGameForNewScreenSize(game->hWnd);
			UI::DisplayStartHUD(game);
			game->player.hasWon = false;
			game->ResetBallAndPlayer();

			game->hasNextLevelLoaded = true;
		}, this).detach();
}