#pragma once

#include"Game.h"

class UI
{
public:
	static const char* characters[];

	static const char* playerLivesToTxt[];

	static int* startUIPositionValues;
	static int* finishGameUIPositionValues;
	static int* scoreUIPositionValues;
	static int* heartsUIPositionValues;

public:
	~UI()
	{
		delete[] startUIPositionValues;
		delete[] finishGameUIPositionValues;
		delete[] scoreUIPositionValues;
		delete[] heartsUIPositionValues;
	}

	static void ShowTextUI(const char* textToDraw, int xPos, int yPos, int width, int height, int letterSpacing, int* UIPositionValues, unsigned int color, Renderer* renderer);
	static void DisplayStartHUD(Game* game);
};