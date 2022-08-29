#pragma once

#include <unordered_map>
#include <string>
#include <array>

#include "raylib.h"

namespace coordinategrid
{

	extern int GameBoxPosX;
	extern int GameBoxPosY;
	extern std::unordered_map<std::string, bool> corruptList;
	extern std::unordered_map<std::string, bool> dangerList;
	void addNewCoordsToLists(std::array<int, 2> myCoordToAdd);
	void initCoordinateGrid();

	bool checkForFullLine(int rowNumber);
	void updateCheckForLineScore(int rowNumber);
	void scanLinesForScore();


	bool isCoordInDanger(std::array<int, 2> myCoord);
	bool isCoordInCorrupt(std::array<int, 2> myCoord);
	void DrawTextureInCoords(Texture2D, int, int, float rotationAmt);






}

