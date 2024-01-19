#pragma once

#include <mutex>
#include "Renderer.h"
#include "Player.h"
#include "Physics.h"
#include "Ball.h"

class Game
{
public:
	bool canAccessFunction = true;

	bool isGameRunning = false;
	bool isInitializationFinished = false;
	int columnsInitialized = -1;
	int columnsToDestroy;

	Renderer renderer;
	float deltaTime = 0;
	Level level;
	BrickType* bricks = nullptr;
	Player player;
	Ball ball;

public:
	~Game()
	{
		free(bricks->imageDecoded);
		delete[] bricks;
	}

	virtual void InitializeObjects();
	virtual void AdaptGameForNewScreenSize(HWND hWnd);
	virtual void ProcessMovableObjects();
	virtual bool ProcessBallCollisionsWithBricks();
	virtual bool ProcessBallCollisionsWithPlayer();
	virtual void ProcessBallCollisionsWithWalls();

private:
	virtual void ProcessEachMovableObject(ObjectBase* object, PhysicsVelocity* physicsVelocityComponent, bool isPlayer);
	virtual void ProcessCollisions();
};