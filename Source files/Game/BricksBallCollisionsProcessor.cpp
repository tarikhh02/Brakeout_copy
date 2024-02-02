#include "Game.h"
#include "UI.h"
#include "Audio.h"

bool Game::ProcessBallCollisionsWithBricks()
{
	Collider::CollisionType collisionType = Collider::NO_COLLISION;

	for (int i = 0; i < level.columnCount * level.rowCount; i++)
	{
		if (bricks[i].id == '_' || bricks[i].isDestroyed)
			continue;

		collisionType = Collider::HandleCollisions(&ball, bricks + i);

		if (collisionType == Collider::BASIC_COLLISION || collisionType == Collider::SIDE_COLLISION || collisionType == Collider::CORNER_COLLISION)
		{
			if (collisionType != Collider::CORNER_COLLISION)
				Physics::SetUpDirectionAfterBasicContact(collisionType, &ball.physicsVelocity, 0);

			if (bricks[i].id != 'I')
			{
				bricks[i].hitPoints--;

				if (bricks[i].hitPoints <= 0)
				{
					bricks[i].isDestroyed = true;
					renderer.ResetTextureFromLastPosition(bricks[i].xPos, bricks[i].yPos, bricks[i].width, bricks[i].height, &level);
					Audio::PlaySoundFromPath(bricks[i].breakSoundPath);

					player.highScore += bricks[i].brickBreakScore;
					
					bricksToDestroy--;

					if (bricksToDestroy <= 0)
					{
						player.hasWon = true;
						FinishGame("YOU WON");
					}
					
					std::thread([](Renderer* renderer, Level* level, int highScore)
						{
							renderer->ResetTextureFromLastPosition(110, renderer->bufferHeight - 25, UI::scoreUIPositionValues[0] + 10, UI::scoreUIPositionValues[1] + 10, level);

							std::string scoreTxt = "SCORE: " + std::to_string(highScore);

							UI::ShowTextUI(scoreTxt.c_str(), 110, renderer->bufferHeight - 25, 200, 35, 3, UI::scoreUIPositionValues, 0x0f0f0f0f, renderer);
						}, &renderer, &level, player.highScore).detach();

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