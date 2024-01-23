#define _CRT_SECURE_NO_WARNINGS

#include "Game.h"

void Game::InitializeObjects()
{
	if (!canAccessFunction)
		return;
	canAccessFunction = false;

	std::string levelText = "Resources\\.xml files\\Level" + std::to_string(++currentLevel) + ".xml";

	XMLDocumentLoader::LoadXMLFile(levelText.c_str());

	if (bricks)
	{
		delete[] bricks;
		free(level.imageDecoded);
	}

	pugi::xml_node node = XMLDocumentLoader::xmlDocument.child("Level");

	level = Level(std::atoi(node.attribute("RowCount").value()), std::atoi(node.attribute("ColumnCount").value()), std::atoi(node.attribute("RowSpacing").value()), 
		std::atoi(node.attribute("ColumnSpacing").value()), 0, 0, node.attribute("BackgroundTexture").value());

	const char* bricksPattern = node.child("Bricks").first_child().value();
	int patternSize = std::strlen(bricksPattern);
	int patternIndex = 0;

	bricks = new BrickType[level.rowCount * level.columnCount];

	for (int y = 0; y < level.rowCount; y++)
	{
		for (int x = 0; x < level.columnCount; x++)
		{
			if (bricksPattern[patternIndex] == '\n' || bricksPattern[patternIndex] == '\t' || bricksPattern[patternIndex] == ' ')
			{
				patternIndex++;
				x--;
				continue;
			}
			
			if(bricksPattern[patternIndex] == '_')
				bricks[y * level.columnCount + x] = BrickType('_', 100, 20, 1, "", "", "", 0);
			else 
			{	
				for (pugi::xml_node brickTypeNode = node.child("BrickTypes").first_child(); brickTypeNode; brickTypeNode = brickTypeNode.next_sibling())
				{
					if((char)brickTypeNode.attribute("Id").value()[0] == bricksPattern[patternIndex])
						bricks[y * level.columnCount + x] = BrickType(bricksPattern[patternIndex], 100, 20, atoi(brickTypeNode.attribute("HitPoints").value()),
																brickTypeNode.attribute("Texture").value(), brickTypeNode.attribute("BreakSound").value(),
																brickTypeNode.attribute("HitSound").value(), atoi(brickTypeNode.attribute("BreakScore").value()));
				}

				if (bricks[y * level.columnCount + x].id != 'I')
					bricksToDestroy++;
			}
			patternIndex++;
		}
	}

	player = Player(150, 20, "Resources\\Images\\playerTexture.jpg");
	ball = Ball(12, 12, "Resources\\Images\\ballTexture.jpg");
	
	isInitializationFinished = true;
	canAccessFunction = true;
}