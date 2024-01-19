#pragma once

#include <malloc.h>

class ObjectBase
{
public: 
	unsigned int* imageDecoded = nullptr;
	const char* texturePath = "brickTxt.jpg";
	int width = 100;
	int height = 20;
	int xPos = 0;
	int yPos = 0;

public:
	ObjectBase(){}
	ObjectBase(int width, int height, const char* texturePath)
	{
		this->width = width;
		this->height = height;
		this->texturePath = texturePath;
	}

	virtual void ObjectInfo() = 0;

	virtual bool DecodeTexture();
	void SetUpNewWidthAndHeight(int width, int height);
	void SetUpNewPosition(int x, int y);

private:
	float PerformBilinearInterpolation(float lowerValue, float higherValue, float ratio);
};

