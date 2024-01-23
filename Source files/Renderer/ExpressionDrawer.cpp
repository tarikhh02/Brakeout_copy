#include "Renderer.h"
#include "UI.h"

void Renderer::DrawExpression(const char* textToDraw, int xStartPosition, int yStartPosition, int xSize, int ySize, int spaceBetweencharacters, unsigned int color)
{
	unsigned int* pixels = (unsigned int*)bufferMemory;

	int x = xStartPosition, y = yStartPosition;

	for (int i = 0; i < strlen(textToDraw); i++)
	{
		int xOrig = x;

		if (textToDraw[i] == ' ')
		{
			x += (spaceBetweencharacters + 6 * xSize);
			continue;
		}

		int index = 0;

		for (index = 0; index < 25; index++)
		{
			if (textToDraw[i] == UI::characters[index][0])
				break;
		}

		if (index >= 25)
			index = 24;

		for (int i = 1; i < strlen(UI::characters[index]); i++)
		{
			if (UI::characters[index][i] == '\n')
			{
				y += ySize;
				x = xOrig;
			}
			else if (UI::characters[index][i] == ' ')
				x += xSize;
			else
			{
				for (int yS = y - ySize / 2; yS <= y + ySize / 2; yS++)
				{
					for (int xS = x - xSize / 2; xS <= x + xSize / 2; xS++)
					{
						pixels[yS * bufferWidth + xS] = color;
					}
				}
				x += xSize;
			}
		}
		x += spaceBetweencharacters;
		y = yStartPosition;
	}
}