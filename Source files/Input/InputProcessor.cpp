#include "Input.h"
#include <windows.h>

unsigned int Input::key = 0;
bool Input::isDown = false;

void Input::ProcessInput(Game* game)
{
	if (key == 'A' && isDown)
		game->player.physicsVelocity.SetDirection(-1, 0);
	else if (key == 'D' && isDown)
		game->player.physicsVelocity.SetDirection(1, 0);
	else if (!isDown && (key == 'A' || key == 'D'))
		game->player.physicsVelocity.SetDirection(0, 0);
	else if (key == VK_ESCAPE && isDown)
		game->StartGame();
}