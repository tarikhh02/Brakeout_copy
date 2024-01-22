#pragma once

#include <mutex>
#include "Renderer.h"
#include "Player.h"
#include "Physics.h"
#include "Ball.h"
#include "XMLDocumentLoader.h"

class Game
{
public:
	bool canAccessFunction = true;
	bool isGameFinished = true;
	bool isGameRunning = true;
	bool isInitializationFinished = false;
	int columnsInitialized = -1;
	int bricksToDestroy;

	float deltaTime = 0;
	float movementDeltaTimeHolder = 0;

	Renderer renderer;
	Level level;
	BrickType* bricks = nullptr;
	Player player;
	Ball ball;

public:
	~Game()
	{
		delete[] bricks;
	}

	virtual void InitializeObjects();
	virtual void AdaptGameForNewScreenSize(HWND hWnd);
	virtual void ProcessMovableObjects();
	virtual bool ProcessBallCollisionsWithBricks();
	virtual bool ProcessBallCollisionsWithPlayer();
	virtual bool ProcessBallCollisionsWithWalls();
	virtual void FinishGame(const char* finishResult);
	virtual void ResetBallAndPlayer();
	virtual void ResetBricks();
	virtual void StartGame();

private:
	virtual void ProcessEachMovableObject(ObjectBase* object, PhysicsVelocity* physicsVelocityComponent, bool isPlayer, float movementDeltaTimeHolder);
	virtual void ProcessCollisions();
};