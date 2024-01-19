#include<thread>
#include "Game.h"

void Game::AdaptGameForNewScreenSize(HWND hWnd)
{
	if (!canAccessFunction || !isInitializationFinished)
		return;
	columnsInitialized = 0;
	canAccessFunction = false;

	renderer.ProcessSizeChangeAndSetMemory(hWnd);
	renderer.SetUpFixedData(&level, bricks);

	player.SetUpNewPosition(renderer.bufferWidth / 2, player.height);
	ball.SetUpNewPosition(renderer.bufferWidth / 2, renderer.bufferHeight / 2);

	if (!level.DecodeTexture())
	{
		canAccessFunction = true;
		return;
	}
	renderer.DrawTexture(level.width / 2, level.height / 2, &level);

	for (int y = 0; y < level.rowCount; y++)
	{
		for (int x = 0; x < level.columnCount; x++)
		{
				if (x == 0 && y == 0)
				{
					if (!bricks[y * level.columnCount + x].DecodeTexture())
					{
						canAccessFunction = true;
						return;
					}
				}
			std::thread([](Renderer* renderer, BrickType* brick, Level* level, int x, int y, int* columnsInitialized, bool* canAccessFunction)
			{
					if (brick->id != '_')
					{
						if (x != 0 || y != 0)
							brick->imageDecoded = brick[-y * level->columnCount - x].imageDecoded;

						renderer->DrawTexture(brick->xPos, brick->yPos, brick);
					}
					*columnsInitialized += 1;
					if(*columnsInitialized == level->columnCount)
						*canAccessFunction = true;
			}, &renderer, (bricks + y * level.columnCount + x), &level, x, y, &columnsInitialized, &canAccessFunction).detach();
		}
	}
}