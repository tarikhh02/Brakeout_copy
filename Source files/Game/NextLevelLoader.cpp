#include "Game.h"
#include "UI.h"

void Game::LoadNextLevel()
{
	if (!hasNextLevelLoaded)
		return;

	hasNextLevelLoaded = false;

	InitializeObjects();
	AdaptGameForNewScreenSize(hWnd);

	std::thread([](Game* game)
		{
			game->player.hasWon = false;
			game->ResetBallAndPlayer();
			game->hasNextLevelLoaded = true;
		}, this).detach();

	UI::DisplayStartHUD(this);
}