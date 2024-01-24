#include "Game.h"
#include "UI.h"

void Game::SetNewScreenSizeAndAdaptUI()
{
	player.livesNumber = 3;
	player.highScore = 0;
	AdaptGameForNewScreenSize(hWnd);
	UI::DisplayStartHUD(this);
	ResetBallAndPlayer();
	ResetBricks();
}