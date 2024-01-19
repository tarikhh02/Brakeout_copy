#include "Game.h"
#include "Audio.h"

bool Game::ProcessBallCollisionsWithBricks()
{
	Collider::CollisionType collisionType = Collider::NO_COLLISION;

	for (int i = 0; i < level.columnCount * level.rowCount; i++)
	{
		if (bricks[i].id == '_')
			continue;

		collisionType = Collider::HandleCollisions(&ball, &ball.physicsVelocity, bricks + i);

		if (collisionType == Collider::BASIC_COLLISION || collisionType == Collider::SIDE_COLLISION || collisionType == Collider::CORNER_COLLISION)
		{
			if (collisionType != Collider::CORNER_COLLISION)
				Physics::SetUpDirectionAfterBasicContact(collisionType, &ball.physicsVelocity, 0);

			if (bricks[i].id != 'I')
			{
				bricks[i].hitPoints--;

				if (bricks[i].hitPoints <= 0)
				{
					bricks[i].id = '_';
					renderer.ResetTextureFromLastPosition(bricks[i].xPos, bricks[i].yPos, bricks[i].width, bricks[i].height, &level);
					Audio::PlaySoundFromPath(bricks[i].breakSoundPath);
					break;
				}
			}

			Audio::PlaySoundFromPath(bricks[i].hitSoundPath);

			break;

		}
	}

	if (collisionType != Collider::NO_COLLISION)
		return true;
	
	return false;
}