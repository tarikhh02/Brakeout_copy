#include "UI.h"

void UI::ShowTextUI(const char* textToDraw, int xPos, int yPos, int width, int height, int letterSpacing, int* UIPositionValues, unsigned int color, Renderer* renderer)
{
	int textLength = strlen(textToDraw);

	int xSize = (width - (textLength * letterSpacing)) / (textLength * 6);
	int ySize = height / 7;
	if (UIPositionValues != nullptr)
	{
		UIPositionValues[1] = (7 * ySize);
		UIPositionValues[0] = (textLength * (6 * xSize + letterSpacing));
	}

	renderer->DrawExpression(textToDraw, xPos - ((textLength * (6 * xSize + letterSpacing)) / 2), yPos - ((7 * ySize) / 2), xSize, ySize, letterSpacing, color);
}