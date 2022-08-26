

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <utility>
#include <typeinfo>

#include "raylib.h"
#include "FallingShape.h"
#include "TexturesLoad.h"
#include "CoordinateGrid.h"
#include "utility.h"
#include "../Logic/game.h"

FallingShape::FallingShape(int typeOfShape)
{
	this->typeOfShape = typeOfShape;

	this->posX = 4;
	this->posY = 0;

	this->stuck = false;

	std::array<int, 2> subCoord1;
	std::array<int, 2> subCoord2;
	std::array<int, 2> subCoord3;
	std::array<int, 2> subCoord4;

	if (this->typeOfShape == 1)
	{

		std::cout << "case 1!" << std::endl;
		this->myTexture = texture::BlockOne;
		makeCoords(this->posX + 1, this->posY + 0, subCoord1);
		makeCoords(this->posX + 1, this->posY + 1, subCoord2);
		makeCoords(this->posX + 1, this->posY + 2, subCoord3);
		makeCoords(this->posX + 1, this->posY + 3, subCoord4);
	}

	if (this->typeOfShape == 2)
	{
		std::cout << "case 2!" << std::endl;
		this->myTexture = texture::BlockTwo;
		makeCoords(this->posX + 2, this->posY + 1, subCoord1);
		makeCoords(this->posX + 1, this->posY + 0, subCoord2);
		makeCoords(this->posX + 0, this->posY + 1, subCoord3);
		makeCoords(this->posX + 1, this->posY + 1, subCoord4);
	}

	if (this->typeOfShape == 3)
	{
		std::cout << "case 3!" << std::endl;
		this->myTexture = texture::BlockThree;
		makeCoords(this->posX + 1, this->posY + 0, subCoord1);
		makeCoords(this->posX + 2, this->posY + 0, subCoord2);
		makeCoords(this->posX + 1, this->posY + 1, subCoord3);
		makeCoords(this->posX + 0, this->posY + 1, subCoord4);
	}

	if (this->typeOfShape == 4)
	{
		std::cout << "case 4!" << std::endl;
		this->myTexture = texture::BlockFour;
		makeCoords(this->posX + 0, this->posY + 0, subCoord1);
		makeCoords(this->posX + 1, this->posY + 0, subCoord2);
		makeCoords(this->posX + 1, this->posY + 1, subCoord3);
		makeCoords(this->posX + 2, this->posY + 1, subCoord4);
	}

	if (this->typeOfShape == 5)
	{

		std::cout << "case 5!" << std::endl;
		this->myTexture = texture::BlockFive;
		makeCoords(this->posX + 0, this->posY + 2, subCoord1);
		makeCoords(this->posX + 0, this->posY + 1, subCoord2);
		makeCoords(this->posX + 1, this->posY + 2, subCoord3);
		makeCoords(this->posX + 2, this->posY + 2, subCoord4);
	}

	if (this->typeOfShape == 6)
	{
		std::cout << "case 6!" << std::endl;
		this->myTexture = texture::BlockSix;
		makeCoords(this->posX + 2, this->posY + 1, subCoord1);
		makeCoords(this->posX + 2, this->posY + 2, subCoord2);
		makeCoords(this->posX + 0, this->posY + 2, subCoord3);
		makeCoords(this->posX + 1, this->posY + 2, subCoord4);
	}

	if (this->typeOfShape == 7)
	{
		std::cout << "case 7!" << std::endl;
		this->myTexture = texture::BlockSeven;
		makeCoords(this->posX + 0, this->posY + 0, subCoord1);
		makeCoords(this->posX + 1, this->posY + 0, subCoord2);
		makeCoords(this->posX + 0, this->posY + 1, subCoord3);
		makeCoords(this->posX + 1, this->posY + 1, subCoord4);
	}

	this->myCurrCoordsList.insert(this->myCurrCoordsList.begin(), subCoord1);
	this->myCurrCoordsList.insert(this->myCurrCoordsList.begin(), subCoord2);
	this->myCurrCoordsList.insert(this->myCurrCoordsList.begin(), subCoord3);
	this->myCurrCoordsList.insert(this->myCurrCoordsList.begin(), subCoord4);
}
FallingShape::~FallingShape()
{
}

void FallingShape::makeCoords(int coordX, int coordY, std::array<int, 2> &mySubCoord)
{
	mySubCoord[0] = coordX;
	mySubCoord[1] = coordY;
}

void FallingShape::shiftLeft()
{
	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		this->myCurrCoordsList[i][0]--;
	}

	this->posX--;
}

void FallingShape::shiftRight()
{

	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		this->myCurrCoordsList[i][0]++;
	}

	this->posX++;
}

void FallingShape::shiftDown()
{

	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		this->myCurrCoordsList[i][1]++;
	}

	this->posY++;
}

void FallingShape::rotateTypeOne()
{

	this->rotation -= 90.0f;
	std::array<std::array<bool, 4>, 4> phleb = {{{false, false, false, false},
												 {false, false, false, false},
												 {false, false, false, false},
												 {false, false, false, false}}};

	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		int col = myCurrCoordsList[i][0] - this->posX;
		int row = myCurrCoordsList[i][1] - this->posY;
		phleb[row][col] = true;
	}
	phleb = utility::rotateMatrixFour(phleb);

	this->myCurrCoordsList.clear();
	for (int i = 0; i < phleb.size(); i++)
	{
		for (int j = 0; j < phleb[i].size(); j++)
		{

			if (phleb[i][j])
			{

				std::array<int, 2> subCoordArray = {j + this->posX, i + this->posY};
				this->myCurrCoordsList.insert(this->myCurrCoordsList.begin(), subCoordArray);
				if (j + this->posX > 8)
					this->shiftLeft();
				if (j + this->posX < 1)
					this->shiftRight();
			}
		}
	}
}

void FallingShape::rotate()
{

	this->rotation -= 90.0f;
	std::array<std::array<bool, 3>, 3> phleb = {{{false, false, false},
												 {false, false, false},
												 {false, false, false}}};

	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		int col = myCurrCoordsList[i][0] - this->posX;
		int row = myCurrCoordsList[i][1] - this->posY;
		phleb[row][col] = true;
	}
	phleb = utility::rotateMatrix(phleb);

	this->myCurrCoordsList.clear();
	for (int i = 0; i < phleb.size(); i++)
	{
		for (int j = 0; j < phleb[i].size(); j++)
		{

			if (phleb[i][j])
			{
				std::array<int, 2> subCoordArray = {j + this->posX, i + this->posY};
				this->myCurrCoordsList.insert(this->myCurrCoordsList.begin(), subCoordArray);
				if (j + this->posX > 8)
					this->shiftLeft();
				if (j + this->posX < 1)
					this->shiftRight();
			}
		}
	}
}

void FallingShape::handleUserKeyInputs()
{
	bool isOutOfBoundsRight = false;
	bool isOutOfBoundsLeft = false;
	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		if (myCurrCoordsList[i][0] > 8)
		{
			isOutOfBoundsRight = true;
		}
		if (myCurrCoordsList[i][0] < 1)
		{
			isOutOfBoundsLeft = true;
		}
	}

	if (IsKeyPressed(KEY_RIGHT) && !isOutOfBoundsRight && !checkForCoordsInDanger())
	{
		this->shiftRight();

		if (checkForCoordsInCorrupt())
		{
			this->shiftLeft();
		}
	}

	if (IsKeyPressed(KEY_LEFT) && !isOutOfBoundsLeft && !checkForCoordsInDanger())
	{
		this->shiftLeft();

		if (checkForCoordsInCorrupt())
		{
			this->shiftRight();
		}
	}

	if (IsKeyPressed(KEY_UP) && this->typeOfShape != 7 && !checkForCoordsInDanger())
	{

		if (this->typeOfShape == 1)
		{
			this->rotateTypeOne();
			return;
		}

		this->rotate();
	}
}

void FallingShape::updateDangerAndCorruptLists()
{

	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		std::string myCorruptKey = coordinategrid::makeKey(this->myCurrCoordsList[i]);
		coordinategrid::addNewCorruptCoord(myCorruptKey);
		std::array<int, 2> myDangerArray = {myCurrCoordsList[i][0], myCurrCoordsList[i][1] - 1};
		std::string myDangerKey = coordinategrid::makeKey(myDangerArray);
		coordinategrid::addNewDangerCoord(myDangerKey);
	}
}

bool FallingShape::checkForCoordsInDanger()
{
	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		std::string myCoordStringKey = coordinategrid::makeKey(myCurrCoordsList[i]);
		if (coordinategrid::dangerList[myCoordStringKey])
		{
			updateDangerAndCorruptLists();
			this->stuck = true;
			return true;
		}
	}
	return false;
}

bool FallingShape::checkForCoordsInCorrupt()
{
	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		std::string myCoordStringKey = coordinategrid::makeKey(myCurrCoordsList[i]);
		if (coordinategrid::corruptList[myCoordStringKey])
		{
			return true;
		}
	}
	return false;
}

void FallingShape::update()
{
	if ((game::frames % 20) == 0 && !checkForCoordsInDanger())
	{

		this->shiftDown();
	}
	this->handleUserKeyInputs();
}

void FallingShape::draw()
{
	coordinategrid::DrawTextureInCoords(this->myTexture, this->posX, this->posY, this->rotation);
}

std::string FallingShape::getCoords()
{
	std::string myString = std::to_string(this->posX) + "," + std::to_string(this->posY);
	return myString;
}

bool FallingShape::getStuck()
{
	return this->stuck;
}

// helper functions------------
