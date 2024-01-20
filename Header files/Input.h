#pragma once

#include "Game.h"

class Input
{
public:
	static unsigned int key;
	static bool isDown;

public:
	static void ProcessInput(Game* game);
};