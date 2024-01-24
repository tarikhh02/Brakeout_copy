#include "Game.h"
#include "XMLDocumentLoader.h"

void Game::ResetBricks()
{
	if (!isInitializationFinished)
		return;

	for (int i = 0; i <= level.columnCount * level.rowCount; i++)
	{
		if (bricks[i].isDestroyed)
		{
			renderer.DrawTexture(bricks[i].xPos, bricks[i].yPos, (bricks + i));
			bricks[i].isDestroyed = false;
			bricksToDestroy++;
		}

		if (bricks[i].hitPoints < bricks[i].hitPointsHolderValue)
			bricks[i].hitPoints = bricks[i].hitPointsHolderValue;
	}
}