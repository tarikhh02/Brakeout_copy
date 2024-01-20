#include "Physics.h"

void Physics::ApplyModifier(float& directionToModify, float modifyingValue)
{
	if (directionToModify > 0)
	{
		directionToModify += modifyingValue;
	}
	else if (directionToModify < 0)
	{
		directionToModify -= modifyingValue;
	}
}