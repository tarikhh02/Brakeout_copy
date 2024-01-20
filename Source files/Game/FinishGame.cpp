#include "Game.h"

void Game::FinishGame(const char* finishResult)
{
	isGameFinished = true;
	ResetBallAndPlayer();
	ResetBricks();
	//Display Finish UI
}