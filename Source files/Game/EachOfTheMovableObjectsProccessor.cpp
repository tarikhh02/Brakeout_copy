#include "Game.h"

void Game::ProcessEachMovableObject(ObjectBase* object, PhysicsVelocity* physicsVelocityComponent, bool isPlayer, float deltaTimeCounterValue)
{
	int lastXPos = object->xPos;
	int lastYPos = object->yPos;

	if(deltaTimeCounterValue > 0.0025)
	{
		Physics::MoveObject(object, physicsVelocityComponent, deltaTimeCounterValue, renderer.bufferWidth, renderer.bufferHeight);

		renderer.ResetTextureFromLastPosition(lastXPos, lastYPos, object->width, object->height, &level);
	}

	if (!isPlayer)
		ProcessCollisions();

	if (!object->imageDecoded)
				object->DecodeTexture();
	renderer.DrawTexture(object->xPos, object->yPos, object);
}