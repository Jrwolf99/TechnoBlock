

#include "CoordinateGrid.h"
#include "raylib.h"
#include "../Screens/gameplay.h"

#include "TexturesLoad.h"
#include "Utility.h"
#include "debug.h"

#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

namespace coordinategrid
{

	int GameBoxPosX;
	int GameBoxPosY;

	std::unordered_map<std::string, bool> corruptList;
	std::unordered_map<std::string, bool> dangerList;


	void addNewCoordsToLists(std::array<int, 2> myCoordToAdd)
	{
		std::string myCorruptCoord = utility::parseArrayToString(myCoordToAdd);
		corruptList[myCorruptCoord] = true;

		std::string myDangerCoord = utility::parseArrayToString(std::array<int, 2> { myCoordToAdd[0], myCoordToAdd[1] - 1});
		dangerList[myDangerCoord] = true;

	}

	void initCoordinateGrid()
	{
		GameBoxPosX = GetScreenWidth() / 2 - texture::GameBox.width / 2;
		GameBoxPosY = GetScreenHeight() / 2 - texture::GameBox.height / 2;

		for (int i = 0; i < 10; i++)
		{

			addNewCoordsToLists(std::array<int, 2>  {i, 20});
		}
	}






	bool checkForFullBottomLine() {
		for (int row = 0; row < 10; row++) {
			if (!isCoordInCorrupt(std::array<int, 2> {row, 19})) {
				return true;
			}
		}
		return false;
	}





	void updateCheckForLineScore() {

		if (checkForFullBottomLine()) {
			return;
		}

		std::cout << "bottom layer SCORE!" << std::endl;
		corruptList.clear();
		dangerList.clear();
		for (int i = 0; i < gameplay::FallingShapesVector.size(); i++) {
			gameplay::FallingShapesVector[i].shiftDown();
			gameplay::FallingShapesVector[i].updateDangerAndCorruptLists();
		}
		//somehow hide the texture below the gamebox. 

	}


	//helper
	bool  isCoordInDanger(std::array<int, 2> myCoord) {
		if (dangerList[utility::parseArrayToString(myCoord)]) return true;
		return false;
	}

	bool  isCoordInCorrupt(std::array<int, 2> myCoord) {
		if (corruptList[utility::parseArrayToString(myCoord)]) return true;
		return false;
	}


	void DrawTextureInCoords(Texture2D Texture, int coordX, int coordY, float rotationAmt)
	{

		float correctedX = (float)(GameBoxPosX + 67 + (27 * coordX));
		float correctedY = (float)(GameBoxPosY + 66 + (27 * coordY));

		Vector2 rotationOrigin = { (float)(Texture.width / 2.0f), (float)Texture.height / 2.0f };

		if (Texture.width > 90.0f)
		{ // this is block one
			correctedX = (float)(GameBoxPosX + 81 + (27 * coordX));
			correctedY = (float)(GameBoxPosY + 80 + (27 * coordY));
		}

		Rectangle sourceRec = { 0.0f, 0.0f, (float)Texture.width, (float)Texture.height };
		Rectangle destRec = { correctedX, correctedY, (float)Texture.width, (float)Texture.height };

		DrawTexturePro(Texture, sourceRec, destRec, rotationOrigin, rotationAmt, WHITE);
	}






}