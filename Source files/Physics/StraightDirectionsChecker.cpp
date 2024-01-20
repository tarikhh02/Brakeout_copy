#include "Physics.h"

void Physics::CheckAndProcessStraightDirections(float& zeroValue, float zeroValueConstraint, float& oneValue, float oneValueConstraint)
{
	if (zeroValue >= -zeroValueConstraint && zeroValue <= zeroValueConstraint
		|| oneValue > oneValueConstraint || oneValue < -oneValueConstraint)
	{
		zeroValue = 0.25f;

		if (oneValue > 0)
			oneValue = 0.75f;
		else if (oneValue < 0)
			oneValue = -0.75f;
	}
}