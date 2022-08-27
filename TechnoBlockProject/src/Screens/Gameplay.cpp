
#include "Gameplay.h"
#include "raylib.h"
#include "../Logic/game.h"
#include "../Utility/FallingShape.h"
#include "../Utility/TexturesLoad.h"
#include "../Utility/CoordinateGrid.h"
#include <iostream>
#include <string>
#include <vector>

// this namespace is the screen for when the player is playing
namespace gameplay
{
	int GameBoxPosX;
	int GameBoxPosY;
	std::vector<FallingShape> FallingShapesVector;

	void init()
	{
		std::cout << " INITIALIZE" << std::endl;
		coordinategrid::initCoordinateGrid();
		GameBoxPosX = GetScreenWidth() / 2 - texture::GameBox.width / 2;
		GameBoxPosY = GetScreenHeight() / 2 - texture::GameBox.height / 2;
		createNewFallingShape(1);
	}

	void createNewFallingShape(int blockType)
	{

		FallingShape myFallingShape(blockType);
		FallingShapesVector.insert(FallingShapesVector.begin(), myFallingShape);
	}

	void update()
	{
		FallingShapesVector[0].update();
		coordinategrid::updateCheckForLineScore();
		if (FallingShapesVector[0].getStuck())
		{
			createNewFallingShape(1);
			//createNewFallingShape((game::frames % 7 + 1));
			game::score++;
		}
	}

	void draw()
	{
		DrawTexture(texture::GameBox, GameBoxPosX, GameBoxPosY, WHITE);
		for (int i = 0; i < FallingShapesVector.size(); i++)
		{
			FallingShapesVector[i].draw();
		}
	}

}