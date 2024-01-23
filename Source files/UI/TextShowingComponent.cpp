#include "UI.h"

void UI::ShowTextUI(const char* textToDraw, int xPos, int yPos, int width, int letterSpacing, int* UIPositionValues, Renderer* renderer)
{
	int textLength = strlen(textToDraw);

	int size = (width - (textLength * letterSpacing)) / (textLength * letterSpacing);

	UIPositionValues[1] = 7 * size;
	UIPositionValues[0] = (textLength * (6 * size + letterSpacing));

	renderer->DrawExpression(textToDraw, xPos - UIPositionValues[0] / 2, yPos - UIPositionValues[1] / 2, size, letterSpacing);
}