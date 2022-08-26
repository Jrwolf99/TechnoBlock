#pragma once
#include "Gameplay.h"
#include "raylib.h"
#include "../Utility/FallingShape.h"
#include "../Utility/TexturesLoad.h"
#include <iostream>

namespace gameplay
{

	extern int GameBoxPosX;
	extern int GameBoxPosY;
	extern std::vector<FallingShape> FallingShapesVector;
	void init();
	void createNewFallingShape(int blockType);
	void update();
	void draw();

}