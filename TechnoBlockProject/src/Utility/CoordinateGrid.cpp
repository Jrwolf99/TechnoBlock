

#include "CoordinateGrid.h"
#include "raylib.h"
#include "../Utility/TexturesLoad.h"
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

	void initCoordinateGrid()
	{
		GameBoxPosX = GetScreenWidth() / 2 - texture::GameBox.width / 2;
		GameBoxPosY = GetScreenHeight() / 2 - texture::GameBox.height / 2;

		for (int i = 0; i < 10; i++)
		{

			std::array<int, 2> myCorruptArray = {i, 20};
			std::array<int, 2> myDangerArray = {i, 19};
			std::string myCorruptKey = makeKey(myCorruptArray);
			std::string myDangerKey = makeKey(myDangerArray);

			corruptList[myCorruptKey] = true;
			dangerList[myDangerKey] = true;

			std::cout << myCorruptKey << " : " << corruptList[myCorruptKey] << std::endl;
			std::cout << myDangerKey << " : " << dangerList[myDangerKey] << std::endl;
		}
	}

	void addNewDangerCoord(std::string myCoordStringKey)
	{

		if (dangerList[myCoordStringKey])
			return;

		std::cout << std::endl
				  << "New Danger Coord Added! : " << myCoordStringKey << std::endl;

		dangerList[myCoordStringKey] = true;
	}

	void addNewCorruptCoord(std::string myCoordStringKey)
	{
		if (corruptList[myCoordStringKey])
			return;

		std::cout << std::endl
				  << "New Corrupt Coord Added! : " << myCoordStringKey << std::endl;

		corruptList[myCoordStringKey] = true;
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

	// helper functions
	std::string makeKey(std::array<int, 2> coordArray)
	{
		std::string myString;
		myString = std::to_string(coordArray[0]) + "," + std::to_string(coordArray[1]);
		return myString;
	}

}