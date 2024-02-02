#pragma once

#include <thread>
#include "Renderer.h"
#include "MovableObject.h"
#include "Physics.h"
#include "XMLDocumentLoader.h"

class Game
{
public:
	bool canAccessFunction = true;
	bool isGameFinished = true;
	bool isGameRunning = true;
	bool isInitializationFinished = false;
	bool hasNextLevelLoaded = true;
	int columnsInitialized = -1;
	int bricksToDestroy;
	
	int currentLevel = 0;

	float deltaTime = 0;
	float movementDeltaTimeHolder = 0;

	HWND hWnd;
	Renderer renderer;
	Level level;
	BrickType* bricks = nullptr;
	MovableObject player;
	MovableObject ball;

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
	virtual void FinishGame(const char* finishText);
	virtual void ResetBallAndPlayer();
	virtual void ResetBricks();
	virtual void StartGame();
	virtual void LoadNextLevel();
	virtual void SetNewScreenSizeAndAdaptUI();

private:
	virtual void ProcessEachMovableObject(MovableObject* object, bool isPlayer, float movementDeltaTimeHolder);
	virtual void ProcessCollisions();
};