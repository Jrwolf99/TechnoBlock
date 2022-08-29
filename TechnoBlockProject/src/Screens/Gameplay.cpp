
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
			game::score = game::score + 8;

			if (FallingShapesVector[0].getY() == FallingShapesVector[1].getY()) {
				game::gameEnded = true;
			}



		}
	}

	void draw()
	{
		GameBoxPosX = GetScreenWidth() / 2 - texture::GameBox.width / 2;
		GameBoxPosY = GetScreenHeight() / 2 - texture::GameBox.height / 2;

		DrawTexture(texture::GameBox, GameBoxPosX, GameBoxPosY, WHITE);
		DrawTexture(texture::Tekno, GameBoxPosX - 55, GameBoxPosY - 150, WHITE);
		DrawText("------ SCORE ------", GameBoxPosX + 375, GameBoxPosY + 50, 24, WHITE);
		DrawText(std::to_string(game::score).c_str(), GameBoxPosX + 400, GameBoxPosY + 100, 24, WHITE);


		for (int i = 0; i < FallingShapesVector.size(); i++)
		{
			FallingShapesVector[i].draw();
		}
	}

}