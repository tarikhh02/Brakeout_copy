#include <cmath>

#include "Physics.h"

float Physics::CalculateAngleModifier(float x, float y)
{
	return sqrt(1 / (x * x + y * y));
}