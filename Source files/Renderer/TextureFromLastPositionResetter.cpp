#include "Renderer.h"

void Renderer::ResetTextureFromLastPosition(int xPos, int yPos, int objectWidth, int objectHeight, Level* level)
{
	if (xPos - objectWidth / 2 < 0 || xPos + objectWidth / 2 > bufferWidth
		|| yPos - objectHeight / 2 < 0 || yPos + objectHeight / 2 > bufferHeight)
		return;

	unsigned int* pixels = (unsigned int*)bufferMemory;
	for (int y = yPos - objectHeight / 2; y < yPos + objectHeight / 2; y++)
	{
		for (int x = xPos - objectWidth / 2; x < xPos + objectWidth / 2; x++)
		{
			pixels[y * bufferWidth + x] = level->imageDecoded[y * bufferWidth + x];
		}
	}
	pixels = nullptr;
}