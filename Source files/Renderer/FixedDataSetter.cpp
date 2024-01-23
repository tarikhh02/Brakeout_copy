#include "Renderer.h"

void Renderer::SetUpFixedData(Level* level, BrickType* bricks)
{
	level->SetUpNewWidthAndHeight(bufferWidth, bufferHeight);

	int newBrickWidth = (bufferWidth - level->coulmnSpacing) / level->columnCount;
	int newBrickHeight = bricks[0].height;

	for (int y = 0; y < level->rowCount; y++)
	{
		int widthToAdd = bufferWidth - level->coulmnSpacing - newBrickWidth * level->columnCount;
		int widthUpdateHolder = 0;
		for (int x = 0; x < level->columnCount; x++)
		{
			int addValue = widthToAdd > 0 ? 1 : 0;

			int modifiedWidth = newBrickWidth - level->coulmnSpacing + addValue;

			bricks[y * level->columnCount + x].SetUpNewWidthAndHeight(modifiedWidth, newBrickHeight);
			bricks[y * level->columnCount + x].SetUpNewPosition(widthUpdateHolder + level->coulmnSpacing + modifiedWidth / 2, bufferHeight - 60 - y * (newBrickHeight + level->rowSpacing) - level->rowSpacing - (newBrickHeight) / 2);

			widthUpdateHolder += modifiedWidth + level->coulmnSpacing;
			widthToAdd--;
		}
	}
}