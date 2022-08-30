

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


	Image GameBoxImage;
	Image BlockOneImage;
	Image BlockTwoImage;
	Image BlockThreeImage;
	Image BlockFourImage;
	Image BlockFiveImage;
	Image BlockSixImage;
	Image BlockSevenImage;



	Texture2D GameBoxGhost;
	Texture2D BlockOneGhost;
	Texture2D BlockTwoGhost;
	Texture2D BlockThreeGhost;
	Texture2D BlockFourGhost;
	Texture2D BlockFiveGhost;
	Texture2D BlockSixGhost;
	Texture2D BlockSevenGhost;


	Texture2D Tekno;
	Image TeknoImage;


	Wave songWave;
	Wave boomWave;
	Wave boomLargeWave;

	Sound song;
	Sound boom;
	Sound boomLarge;


	void LoadTextures()
	{



		/*	GameBoxImage = LoadImage("./TechnoBlockProject/resources/images/GameBox.png");
			BlockOneImage = LoadImage("./TechnoBlockProject/resources/images/BlockOne.png");
			BlockTwoImage = LoadImage("./TechnoBlockProject/resources/images/BlockTwo.png");
			BlockThreeImage = LoadImage("./TechnoBlockProject/resources/images/BlockThree.png");
			BlockFourImage = LoadImage("./TechnoBlockProject/resources/images/BlockFour.png");
			BlockFiveImage = LoadImage("TechnoBlockProject/resources/images/BlockFive.png");
			BlockSixImage = LoadImage("./TechnoBlockProject/resources/images/BlockSix.png");
			BlockSevenImage = LoadImage("./TechnoBlockProject/resources/images/BlockSeven.png");
			TeknoImage = LoadImage("./TechnoBlockProject/resources/images/Tekno.png");*/



		GameBoxImage = LoadImage("resources/images/GameBox.png");
		BlockOneImage = LoadImage("resources/images/BlockOne.png");
		BlockTwoImage = LoadImage("resources/images/BlockTwo.png");
		BlockThreeImage = LoadImage("resources/images/BlockThree.png");
		BlockFourImage = LoadImage("resources/images/BlockFour.png");
		BlockFiveImage = LoadImage("resources/images/BlockFive.png");
		BlockSixImage = LoadImage("resources/images/BlockSix.png");
		BlockSevenImage = LoadImage("resources/images/BlockSeven.png");
		TeknoImage = LoadImage("resources/images/Tekno.png");




		GameBox = LoadTextureFromImage(GameBoxImage);
		BlockOne = LoadTextureFromImage(BlockOneImage);
		BlockTwo = LoadTextureFromImage(BlockTwoImage);
		BlockThree = LoadTextureFromImage(BlockThreeImage);
		BlockFour = LoadTextureFromImage(BlockFourImage);
		BlockFive = LoadTextureFromImage(BlockFiveImage);
		BlockSix = LoadTextureFromImage(BlockSixImage);
		BlockSeven = LoadTextureFromImage(BlockSevenImage);
		Tekno = LoadTextureFromImage(TeknoImage);






		BlockOneGhost = LoadTexture("resources/images/BlockOneGhost.png");
		BlockTwoGhost = LoadTexture("resources/images/BlockTwoGhost.png");
		BlockThreeGhost = LoadTexture("resources/images/BlockThreeGhost.png");
		BlockFourGhost = LoadTexture("resources/images/BlockFourGhost.png");
		BlockFiveGhost = LoadTexture("resources/images/BlockFiveGhost.png");
		BlockSixGhost = LoadTexture("resources/images/BlockSixGhost.png");
		BlockSevenGhost = LoadTexture("resources/images/BlockSevenGhost.png");


		songWave = LoadWave("resources/sounds/song.wav");
		boomWave = LoadWave("resources/sounds/boom.wav");
		boomLargeWave = LoadWave("resources/sounds/boomlarge.wav");

		song = LoadSoundFromWave(songWave);
		boom = LoadSoundFromWave(boomWave);
		boomLarge = LoadSoundFromWave(boomLargeWave);


	}

}