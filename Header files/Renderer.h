#pragma once
#include <windows.h>
#include "BrickType.h"
#include "Level.h"

class Renderer
{
public: 
	int bufferHeight;
	int bufferWidth;
	void* bufferMemory;
	BITMAPINFO bufferBitInfo;

public:
	~Renderer()
	{
		if (bufferMemory)
			free(bufferMemory);
	}

	virtual void DrawTexture(int positionX, int positionY, ObjectBase* objectTextureComponent);
	virtual void SetUpFixedData(Level* level, BrickType* bricks);
	virtual void ProcessSizeChangeAndSetMemory(HWND hWnd);
	virtual void ResetTextureFromLastPosition(int xPos, int yPos, int objectWidth, int objectHeight, Level* level);
	virtual void DrawExpression(const char* textToDraw, int xStartPosition, int yStartPosition, int size, int spaceBetweenLetters);

private:
	virtual void SetBitInfo();
};

