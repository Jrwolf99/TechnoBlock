

#include "CoordinateGrid.h"
#include "raylib.h"
#include "../Screens/gameplay.h"
#include "../Utility/TexturesLoad.h"
#include "../Utility/Utility.h"
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

		std::string myDangerCoord = utility::parseArrayToString(std::array<int, 2> { myCoordToAdd[0], myCoordToAdd[1]-1});
		dangerList[myDangerCoord] = true;

	}




	void initCoordinateGrid()
	{
		GameBoxPosX = GetScreenWidth() / 2 - texture::GameBox.width / 2;
		GameBoxPosY = GetScreenHeight() / 2 - texture::GameBox.height / 2;

		for (int i = 0; i < 10; i++)
		{
			corruptList[utility::parseArrayToString(std::array<int, 2>  {i, 20})] = true;
			dangerList[utility::parseArrayToString(std::array<int, 2> {i, 19})] = true;
		}
	}


	void updateCheckForLineScore() {
		//scan corrupt list
		//if all 10 columns of row 19 are not filled, we know player hasn't scored
		for (int i = 0; i < 10; i++) {
			std::array<int, 2> myCoord = {i, 19};
			if (!corruptList[utility::parseArrayToString(myCoord)]) {
				return;
			}
		}
		std::cout << "bottom layer SCORE!"<< std::endl;


		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 25; j++) {

				std::array<int, 2> myArray = { i, j };
				std::string myCoordsKey = utility::parseArrayToString(myArray);
				std::cout << "CORRUPT LIST Value at : " << myCoordsKey << " : " << corruptList[myCoordsKey] << std::endl;

			}
		}


		//shift all corruptlist and danger list coords down
		corruptList = utility::shiftHashValuesDown(corruptList);
		dangerList = utility::shiftHashValuesDown(dangerList);


		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 25; j++) {

				std::array<int, 2> myArray = { i, j };
				std::string myCoordsKey = utility::parseArrayToString(myArray);
				std::cout << "CORRUPT LIST Value at : " << myCoordsKey << " : " << corruptList[myCoordsKey] << std::endl;


			}
		}

		//shift all values down of each FallingShape of the FallingShapesVector
		for (int i = 0; i < gameplay::FallingShapesVector.size(); i++) {
			gameplay::FallingShapesVector[i].shiftDown();
		}
		//somehow hide the texture below the gamebox. 



	}


	//helper
	bool  isCoordInDanger(std::array<int, 2> myCoord) {
		if (coordinategrid::dangerList[utility::parseArrayToString(myCoord)]) return true;
		return false;
	}


	void DrawTextureInCoords(Texture2D Texture, int coordX, int coordY, float rotationAmt)
	{

		float correctedX = (float)(GameBoxPosX + 67 + (27 * coordX));
		float correctedY = (float)(GameBoxPosY + 66 + (27 * coordY));

		Vector2 rotationOrigin = {(float)(Texture.width / 2.0f), (float)Texture.height / 2.0f};

		if (Texture.width > 90.0f)
		{ // this is block one
			correctedX = (float)(GameBoxPosX + 81 + (27 * coordX));
			correctedY = (float)(GameBoxPosY + 80 + (27 * coordY));
		}

		Rectangle sourceRec = {0.0f, 0.0f, (float)Texture.width, (float)Texture.height};
		Rectangle destRec = {correctedX, correctedY, (float)Texture.width, (float)Texture.height};

		DrawTexturePro(Texture, sourceRec, destRec, rotationOrigin, rotationAmt, WHITE);
	}


	

	

}