#include "UI.h"

void UI::ShowTextUI(const char* textToDraw, int xPos, int yPos, int width, int height, int letterSpacing, int* UIPositionValues, Renderer* renderer)
{
	int textLength = strlen(textToDraw);

	int xSize = (width - (textLength * letterSpacing)) / (textLength * 6);
	int ySize = height / 7;

	UIPositionValues[1] = 7 * ySize;
	UIPositionValues[0] = (textLength * (6 * xSize + letterSpacing));

	renderer->DrawExpression(textToDraw, xPos - UIPositionValues[0] / 2, yPos - UIPositionValues[1] / 2, xSize, ySize, letterSpacing);
}