#pragma once

#include "Player.h"

class Input
{
public:
	static unsigned int key;
	static bool isDown;

public:
	static void ProcessInput(Player* player);
};