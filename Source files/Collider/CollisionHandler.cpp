#include "Collider.h"
#include "Physics.h"

Collider::CollisionType Collider::HandleCollisions(ObjectBase* objectThatCollides, PhysicsVelocity* objectPhysicsVelocityComponent, ObjectBase* objectWithWhichCollidesWith)
{
	int offSet = 2;

	for (int y = 1; y >= -1; y -= 2)
	{
		int xSideValue = objectThatCollides->xPos + y * (objectThatCollides->width / 2);
		int ySideValue = objectThatCollides->yPos + y * (objectThatCollides->width / 2);

		if (CheckAxis(xSideValue, objectThatCollides->yPos,
			objectWithWhichCollidesWith->xPos - objectWithWhichCollidesWith->width / 2,
			objectWithWhichCollidesWith->xPos + objectWithWhichCollidesWith->width / 2,
			objectWithWhichCollidesWith->yPos - objectWithWhichCollidesWith->height / 2,
			objectWithWhichCollidesWith->yPos + objectWithWhichCollidesWith->height / 2))
		{
			int xNewPos = objectWithWhichCollidesWith->xPos + (-1 * y * (objectWithWhichCollidesWith->width / 2 + objectThatCollides->width / 2 + offSet));
			objectThatCollides->SetUpNewPosition(xNewPos, objectThatCollides->yPos);
			return SIDE_COLLISION;
		}

		if (CheckAxis(objectThatCollides->xPos, ySideValue,
			objectWithWhichCollidesWith->xPos - objectWithWhichCollidesWith->width / 2,
			objectWithWhichCollidesWith->xPos + objectWithWhichCollidesWith->width / 2,
			objectWithWhichCollidesWith->yPos - objectWithWhichCollidesWith->height / 2,
			objectWithWhichCollidesWith->yPos + objectWithWhichCollidesWith->height / 2))
		{
			int yNewPos = objectWithWhichCollidesWith->yPos + (-1 * y * (objectWithWhichCollidesWith->height / 2 + objectThatCollides->height / 2 + offSet));
			objectThatCollides->SetUpNewPosition(objectThatCollides->xPos, yNewPos);
			return BASIC_COLLISION;
		}
	}

	for (int y = 1; y >= -1; y -= 2)
	{
		for (int x = -1; x <= 1; x += 2)
		{
			int xCornerValues = objectThatCollides->xPos + x * (objectThatCollides->width / 2);
			int yCornerValues = objectThatCollides->yPos + y * (objectThatCollides->height / 2);

			if (CheckAxis(xCornerValues, yCornerValues,
				(objectWithWhichCollidesWith->xPos + (x * -1) * (objectWithWhichCollidesWith->width / 2) + (x * objectThatCollides->width / 2)),
				(objectWithWhichCollidesWith->xPos + (x * -1) * (objectWithWhichCollidesWith->width / 2)),
				(objectWithWhichCollidesWith->yPos + (y * -1) * (objectWithWhichCollidesWith->height / 2) + (y * objectThatCollides->width / 2)),
				(objectWithWhichCollidesWith->yPos + (y * -1) * (objectWithWhichCollidesWith->height / 2))))
			{
				Physics::SetUpDirectionAfterCornerContact(objectPhysicsVelocityComponent, -x, -y);

				int xNewPos = objectWithWhichCollidesWith->xPos + (x * -1) * (objectWithWhichCollidesWith->width / 2 + objectThatCollides->width / 2 + offSet);
				int yNewPos = objectWithWhichCollidesWith->yPos + (y * -1) * (objectWithWhichCollidesWith->height / 2 + objectThatCollides->height / 2 + offSet);
				objectThatCollides->SetUpNewPosition(xNewPos, yNewPos);

				return CORNER_COLLISION;
			}
		}
	}

	return NO_COLLISION;
}

bool Collider::CheckAxis(int x, int y, int xConstraint1, int xConstraint2, int yConstraint1, int yConstraint2)
{
	if (xConstraint2 < xConstraint1)
	{
		int temp = xConstraint1;
		xConstraint1 = xConstraint2;
		xConstraint2 = temp;
	}

	if (yConstraint2 < yConstraint1)
	{
		int temp = yConstraint1;
		yConstraint1 = yConstraint2;
		yConstraint2 = temp;
	}

	if (x >= xConstraint1 && x <= xConstraint2 && y >= yConstraint1 && y <= yConstraint2)
		return true;

	return false;
}