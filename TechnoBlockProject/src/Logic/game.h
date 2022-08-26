#pragma once
#include "raylib.h"

namespace game
{

	extern const int screenWidth;
	extern const int screenHeight;

	extern int frames;
	extern int secondsPassed;

	void runApplication();
	void init();
	void deInit();
	void update();
	void draw();
}
