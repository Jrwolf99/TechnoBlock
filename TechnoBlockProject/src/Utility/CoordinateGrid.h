#pragma once

#include <unordered_map>
#include <string>

#include "raylib.h"

namespace coordinategrid
{

	extern int GameBoxPosX;
	extern int GameBoxPosY;
	extern std::unordered_map<std::string, bool> corruptList;
	extern std::unordered_map<std::string, bool> dangerList;
	void DrawTextureInCoords(Texture2D, int, int, float rotationAmt);
	void addNewDangerCoord(std::string myCoordStringKey);
	void addNewCorruptCoord(std::string myCoordStringKey);
	void initCoordinateGrid();
	std::string makeKey(std::array<int, 2>);


}

