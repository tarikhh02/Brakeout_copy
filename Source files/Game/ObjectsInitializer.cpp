#include "Game.h"

void Game::InitializeObjects()
{
	if (!canAccessFunction)
		return;
	canAccessFunction = false;

	level = Level(3, 20, 3, 3, 0, 0, "Resources\\Images\\backgroundTexture.jpg");

	bricks = new BrickType[level.rowCount * level.columnCount];

	for (int y = 0; y < level.rowCount; y++)
	{
		for (int x = 0; x < level.columnCount; x++)
		{
			bricks[y * level.columnCount + x] = BrickType('H', 100, 20, 3, "Resources\\Images\\softBrickTexture.jpg", "Resources\\Sounds\\softBrickHitSound.wav", "Resources\\Sounds\\softBrickBreakingSound.wav");
		}
	}

	player = Player(150, 20, "Resources\\Images\\playerTexture.jpg");
	ball = Ball(12, 12, "Resources\\Images\\ballTexture.jpg");

	columnsToDestroy = level.columnCount * level.rowCount;

	isInitializationFinished = true;
	canAccessFunction = true;
}