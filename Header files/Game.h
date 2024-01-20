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
	bool isGameFinished = true;
	bool isGameRunning = true;
	bool isInitializationFinished = false;
	int columnsInitialized = -1;
	int bricksToDestroy;

	Renderer renderer;
	float deltaTime = 0.0167;
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
	virtual bool ProcessBallCollisionsWithWalls();
	virtual void FinishGame(const char* finishResult);
	virtual void ResetBallAndPlayer();
	virtual void ResetBricks();
	virtual void StartGame();

private:
	virtual void ProcessEachMovableObject(ObjectBase* object, PhysicsVelocity* physicsVelocityComponent, bool isPlayer);
	virtual void ProcessCollisions();
};