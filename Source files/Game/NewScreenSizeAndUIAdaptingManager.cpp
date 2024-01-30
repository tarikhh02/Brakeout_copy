#include "Game.h"
#include "UI.h"

void Game::SetNewScreenSizeAndAdaptUI()
{
	player.livesNumber = 3;
	player.highScore = 0;
	AdaptGameForNewScreenSize(hWnd);
	std::thread([this]() { UI::DisplayStartHUD(this); }).detach();
	std::thread([this]() {this->ResetBallAndPlayer();}).detach();
	std::thread([this]() {this->ResetBricks();}).detach();
}