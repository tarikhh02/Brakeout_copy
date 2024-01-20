#include "Game.h"

void Game::ProcessEachMovableObject(ObjectBase* object, PhysicsVelocity* physicsVelocityComponent, bool isPlayer)
{
	int lastXPos = object->xPos;
	int lastYPos = object->yPos;

	Physics::MoveObject(object, physicsVelocityComponent, deltaTime, renderer.bufferWidth, renderer.bufferHeight);

	renderer.ResetTextureFromLastPosition(lastXPos, lastYPos, object->width, object->height, &level);

	if (!isPlayer)
		ProcessCollisions();

	if (!object->imageDecoded)
				object->DecodeTexture();
	renderer.DrawTexture(object->xPos, object->yPos, object);
}