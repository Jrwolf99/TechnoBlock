#include <iostream>
#include "game.h"
#include "raylib.h"
#include "../Utility/TexturesLoad.h"
#include "../Screens/gameplay.h"

namespace game
{
	const int screenWidth = 1200;
	const int screenHeight = 700;
	int frames = 0;
	int secondsPassed = 0;

	void runApplication()
	{
		init();
		while (!WindowShouldClose())
		{
			frames++;
			if (frames % 60 == 0)
			{
				secondsPassed++;
			}

			update();
			draw();
		}
		deInit();
	}

	// Initialization of all the game!
	void init()
	{
		InitWindow(screenWidth, screenHeight, "Block Game! by Jonathan Wolf");
		texture::LoadTextures();
		SetTargetFPS(60);
		SetConfigFlags(FLAG_MSAA_4X_HINT);
		gameplay::init();
	}

	void update()
	{
		gameplay::update();
	}

	void draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		gameplay::draw();
		EndDrawing();
	}
	void deInit()
	{
		CloseWindow();
	}

}