#include "Renderer.h"

void Renderer::DrawTexture(int positionX, int positionY, ObjectBase* object)
{
	if (positionX - object->width / 2 < 0 || positionX + object->width / 2 > bufferWidth
		|| positionY - object->height / 2 < 0 || positionY + object->height / 2 > bufferHeight)
		return;

	unsigned int* pixels = (unsigned int*)bufferMemory;

	for (int y = positionY - object->height / 2; y < positionY + object->height / 2; y++)
	{
		for (int x = positionX - object->width / 2; x < positionX + object->width / 2; x++)
		{
			pixels[y * bufferWidth + x] = object->imageDecoded[(y - positionY + object->height / 2) * object->width + (x - positionX + object->width / 2)];
		}
	}

	pixels = nullptr;
}