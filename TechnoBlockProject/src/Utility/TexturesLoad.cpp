

#include "TexturesLoad.h"
#include "raylib.h"
#include <iostream>

namespace texture
{
	Texture2D GameBox;
	Texture2D BlockOne;
	Texture2D BlockTwo;
	Texture2D BlockThree;
	Texture2D BlockFour;
	Texture2D BlockFive;
	Texture2D BlockSix;
	Texture2D BlockSeven;
	Texture2D Tekno;

	Sound song;
	Sound boom;
	Sound boomLarge;

	void LoadTextures()
	{
		GameBox = LoadTexture("./TechnoBlockProject/resources/images/GameBox.png");
		BlockOne = LoadTexture("./TechnoBlockProject/resources/images/BlockOne.png");
		BlockTwo = LoadTexture("./TechnoBlockProject/resources/images/BlockTwo.png");
		BlockThree = LoadTexture("./TechnoBlockProject/resources/images/BlockThree.png");
		BlockFour = LoadTexture("./TechnoBlockProject/resources/images/BlockFour.png");
		BlockFive = LoadTexture("TechnoBlockProject/resources/images/BlockFive.png");
		BlockSix = LoadTexture("./TechnoBlockProject/resources/images/BlockSix.png");
		BlockSeven = LoadTexture("./TechnoBlockProject/resources/images/BlockSeven.png");
		Tekno = LoadTexture("./TechnoBlockProject/resources/images/Tekno.png");

		song = LoadSound("./TechnoBlockProject/resources/sounds/song.wav");
		boom = LoadSound("./TechnoBlockProject/resources/sounds/boom.wav");
		boomLarge = LoadSound("./TechnoBlockProject/resources/sounds/boomlarge.wav");

	}

}