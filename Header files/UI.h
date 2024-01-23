#pragma once

#include "Renderer.h"

class UI
{
public:
	static const char* characters[];

	static int* startUIPositionValues;
	static int* finishGameUIPositionValues;
	static int* scoreUIPositionValues;

public:
	~UI()
	{
		delete[] startUIPositionValues;
		delete[] finishGameUIPositionValues;
		delete[] scoreUIPositionValues;
	}

	static void ShowTextUI(const char* textToDraw, int xPos, int yPos, int width, int letterSpacing, int* UIPositionValues, Renderer* renderer);
};