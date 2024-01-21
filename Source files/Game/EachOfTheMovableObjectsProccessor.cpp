#include "Game.h"

void Game::ProcessEachMovableObject(ObjectBase* object, PhysicsVelocity* physicsVelocityComponent, bool isPlayer)
{
	int lastXPos = object->xPos;
	int lastYPos = object->yPos;

	movementDeltaTimeHolder += deltaTime;

	if (movementDeltaTimeHolder >= 0.0025)
	{
		Physics::MoveObject(object, physicsVelocityComponent, movementDeltaTimeHolder, renderer.bufferWidth, renderer.bufferHeight);

		renderer.ResetTextureFromLastPosition(lastXPos, lastYPos, object->width, object->height, &level);

		movementDeltaTimeHolder = 0;
	}

	if (!isPlayer)
		ProcessCollisions();

	if (!object->imageDecoded)
				object->DecodeTexture();
	renderer.DrawTexture(object->xPos, object->yPos, object);
}