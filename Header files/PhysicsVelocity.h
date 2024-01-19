#pragma once

class PhysicsVelocity
{
public:
	float xDirection = 0;
	float yDirection = 0;
	float velocity = 0;

public:
	PhysicsVelocity(){}
	PhysicsVelocity(float xDirection, float yDirection, float velocity) 
	{
		this->xDirection = xDirection;
		this->yDirection = yDirection;
		this->velocity = velocity;
	}

	void SetDirection(float xDirection, float yDirection);
	void SetVelocity(float velocity);
};