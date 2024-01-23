#include "Renderer.h"
#include "UI.h"

void Renderer::DrawExpression(const char* textToDraw, int xStartPosition, int yStartPosition, int size, int spaceBetweencharacters)
{
	unsigned int* pixels = (unsigned int*)bufferMemory;

	int x = xStartPosition, y = yStartPosition;

	for (int i = 0; i < strlen(textToDraw); i++)
	{
		int xOrig = x;

		if (textToDraw[i] == ' ')
		{
			x += (spaceBetweencharacters + 6 * size);
			continue;
		}

		int index = 0;

		for (index = 0; index < 23; index++)
		{
			if (textToDraw[i] == UI::characters[index][0])
				break;
		}
		for (int i = 1; i < strlen(UI::characters[index]); i++)
		{
			if (UI::characters[index][i] == '\n')
			{
				y += size;
				x = xOrig;
			}
			else if (UI::characters[index][i] == ' ')
				x += size;
			else
			{
				for (int ySize = y - size / 2; ySize <= y + size / 2; ySize++)
				{
					for (int xSize = x - size / 2; xSize <= x + size / 2; xSize++)
					{
						pixels[ySize * bufferWidth + xSize] = 0x0f0f0f0f;
					}
				}
				x += size;
			}
		}
		x += spaceBetweencharacters;
		y = yStartPosition;
	}
}