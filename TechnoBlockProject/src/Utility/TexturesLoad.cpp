

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

	Texture2D GameBoxGhost;
	Texture2D BlockOneGhost;
	Texture2D BlockTwoGhost;
	Texture2D BlockThreeGhost;
	Texture2D BlockFourGhost;
	Texture2D BlockFiveGhost;
	Texture2D BlockSixGhost;
	Texture2D BlockSevenGhost;


	Texture2D Tekno;


	Wave songWave;
	Wave boomWave;
	Wave boomLargeWave;

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


		BlockOneGhost = LoadTexture("./TechnoBlockProject/resources/images/BlockOneGhost.png");
		BlockTwoGhost = LoadTexture("./TechnoBlockProject/resources/images/BlockTwoGhost.png");
		BlockThreeGhost = LoadTexture("./TechnoBlockProject/resources/images/BlockThreeGhost.png");
		BlockFourGhost = LoadTexture("./TechnoBlockProject/resources/images/BlockFourGhost.png");
		BlockFiveGhost = LoadTexture("TechnoBlockProject/resources/images/BlockFiveGhost.png");
		BlockSixGhost = LoadTexture("./TechnoBlockProject/resources/images/BlockSixGhost.png");
		BlockSevenGhost = LoadTexture("./TechnoBlockProject/resources/images/BlockSevenGhost.png");




		songWave = LoadWave("./TechnoBlockProject/resources/sounds/song.wav");
		boomWave = LoadWave("./TechnoBlockProject/resources/sounds/boom.wav");
		boomLargeWave = LoadWave("./TechnoBlockProject/resources/sounds/boomlarge.wav");

		song = LoadSoundFromWave(songWave);
		boom = LoadSoundFromWave(boomWave);
		boomLarge = LoadSoundFromWave(boomLargeWave);







	}

}