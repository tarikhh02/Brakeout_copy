#include "Input.h"
#include <windows.h>

unsigned int Input::key = 0;
bool Input::isDown = false;

void Input::ProcessInput(Player* player)
{
	if (key == 'A' && isDown)
		player->physicsVelocity.SetDirection(-1, 0);
	else if (key == 'D' && isDown)
		player->physicsVelocity.SetDirection(1, 0);
	else if(!isDown && (key == 'A' || key == 'D'))
		player->physicsVelocity.SetDirection(0, 0);
}