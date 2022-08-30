#include <iostream>
#include "game.h"
#include "raylib.h"
#include "../Utility/TexturesLoad.h"
#include "../Screens/gameplay.h"

namespace game
{
	const int screenWidth = GetMonitorWidth(0);
	const int screenHeight = GetMonitorWidth(0);
	int frames = 0;
	int secondsPassed = 0;
	int score = 0;
	bool gameEnded = false;


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

			if (!gameEnded) update();
			draw();

		}
		deInit();
	}

	// Initialization of all the game!
	void init()
	{
		SetConfigFlags(FLAG_WINDOW_RESIZABLE);
		InitWindow(0, 0, "Block Game! by Jonathan Wolf");
		InitAudioDevice();
		texture::LoadTextures();
		PlaySound(texture::song);
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



		if (gameEnded) {

			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
			DrawText("------ GAME OVER ------", GetScreenWidth() / 2 - MeasureText("------ GAVE OVER ------", 24) / 2, GetScreenHeight() / 2, 24, WHITE);

			auto myScore = std::to_string(game::score);
			const char* myChar = myScore.c_str();

			DrawText(myChar, (GetScreenWidth() / 2) - (MeasureText(myChar, 24) / 2), GetScreenHeight() / 2 + 50, 24, WHITE);


		}


		EndDrawing();
	}
	void deInit()
	{


		CloseAudioDevice();
		CloseWindow();
	}

}