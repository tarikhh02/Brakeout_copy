#include "Game.h"

void Game::ResetBricks()
{
	for (int i = 0; i <= level.columnCount * level.rowCount; i++)
	{
		if (bricks[i].isDestroyed)
		{
			renderer.DrawTexture(bricks[i].xPos, bricks[i].yPos, (bricks + i));
			bricks[i].isDestroyed = false;
			bricks[i].hitPoints = 2;
			bricksToDestroy++;
		}
	}
}