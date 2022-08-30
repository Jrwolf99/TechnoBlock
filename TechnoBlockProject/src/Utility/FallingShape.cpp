

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
		this->myTextureGhost = texture::BlockOneGhost;
		makeCoords(this->posX + 1, this->posY + 0, subCoord1);
		makeCoords(this->posX + 1, this->posY + 1, subCoord2);
		makeCoords(this->posX + 1, this->posY + 2, subCoord3);
		makeCoords(this->posX + 1, this->posY + 3, subCoord4);
	}

	if (this->typeOfShape == 2)
	{
		std::cout << "case 2!" << std::endl;
		this->myTexture = texture::BlockTwo;
		this->myTextureGhost = texture::BlockTwoGhost;
		makeCoords(this->posX + 2, this->posY + 1, subCoord1);
		makeCoords(this->posX + 1, this->posY + 0, subCoord2);
		makeCoords(this->posX + 0, this->posY + 1, subCoord3);
		makeCoords(this->posX + 1, this->posY + 1, subCoord4);
	}

	if (this->typeOfShape == 3)
	{
		std::cout << "case 3!" << std::endl;
		this->myTexture = texture::BlockThree;
		this->myTextureGhost = texture::BlockThreeGhost;
		makeCoords(this->posX + 1, this->posY + 0, subCoord1);
		makeCoords(this->posX + 2, this->posY + 0, subCoord2);
		makeCoords(this->posX + 1, this->posY + 1, subCoord3);
		makeCoords(this->posX + 0, this->posY + 1, subCoord4);
	}

	if (this->typeOfShape == 4)
	{
		std::cout << "case 4!" << std::endl;
		this->myTexture = texture::BlockFour;
		this->myTextureGhost = texture::BlockFourGhost;
		makeCoords(this->posX + 0, this->posY + 0, subCoord1);
		makeCoords(this->posX + 1, this->posY + 0, subCoord2);
		makeCoords(this->posX + 1, this->posY + 1, subCoord3);
		makeCoords(this->posX + 2, this->posY + 1, subCoord4);
	}

	if (this->typeOfShape == 5)
	{

		std::cout << "case 5!" << std::endl;
		this->myTexture = texture::BlockFive;
		this->myTextureGhost = texture::BlockFiveGhost;
		makeCoords(this->posX + 0, this->posY + 2, subCoord1);
		makeCoords(this->posX + 0, this->posY + 1, subCoord2);
		makeCoords(this->posX + 1, this->posY + 2, subCoord3);
		makeCoords(this->posX + 2, this->posY + 2, subCoord4);
	}

	if (this->typeOfShape == 6)
	{
		std::cout << "case 6!" << std::endl;
		this->myTexture = texture::BlockSix;
		this->myTextureGhost = texture::BlockSixGhost;
		makeCoords(this->posX + 2, this->posY + 1, subCoord1);
		makeCoords(this->posX + 2, this->posY + 2, subCoord2);
		makeCoords(this->posX + 0, this->posY + 2, subCoord3);
		makeCoords(this->posX + 1, this->posY + 2, subCoord4);
	}

	if (this->typeOfShape == 7)
	{
		std::cout << "case 7!" << std::endl;
		this->myTexture = texture::BlockSeven;
		this->myTextureGhost = texture::BlockSevenGhost;
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

void FallingShape::makeCoords(int coordX, int coordY, std::array<int, 2>& mySubCoord)
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


	if (checkForCoordsInCorrupt())
	{
		this->shiftRight();
	}



}

void FallingShape::shiftRight()
{

	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		this->myCurrCoordsList[i][0]++;
	}

	this->posX++;


	if (checkForCoordsInCorrupt())
	{
		this->shiftLeft();
	}


}

void FallingShape::shiftDown()
{

	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		this->myCurrCoordsList[i][1]++;
	}

	this->posY++;




}

bool FallingShape::CheckForCoordsInSides()
{
	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		if (this->myCurrCoordsList[i][0] > 9 || this->myCurrCoordsList[i][0] < 0) {
			return true;
		}
	}
	return false;
}

bool FallingShape::checkForCoordsInDanger()
{
	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		if (coordinategrid::isCoordInDanger(this->myCurrCoordsList[i]))
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
		std::string myCoordStringKey = utility::parseArrayToString(myCurrCoordsList[i]);
		if (coordinategrid::corruptList[myCoordStringKey])
		{
			return true;
		}
	}
	return false;
}

void FallingShape::assignCoordsToMatrix(std::vector<std::vector<bool>>& myMatrix) {
	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		int col = myCurrCoordsList[i][0] - this->posX;
		int row = myCurrCoordsList[i][1] - this->posY;
		myMatrix[row][col] = true;
	}
}


void FallingShape::fillMyCoordsAsRotatedCoords(std::vector<std::vector<bool>> myMatrix) {
	this->myCurrCoordsList.clear();
	for (int i = 0; i < myMatrix.size(); i++)
	{
		for (int j = 0; j < myMatrix[i].size(); j++)
		{
			if (myMatrix[i][j])
			{
				std::array<int, 2> subCoordArray = { j + this->posX, i + this->posY };
				this->myCurrCoordsList.insert(this->myCurrCoordsList.begin(), subCoordArray);
			}
		}
	}


}


bool FallingShape::isHittingEdge(std::string side, std::vector<std::vector<bool>> myMatrix) {
	for (int i = 0; i < myMatrix.size(); i++)
	{
		for (int j = 0; j < myMatrix[i].size(); j++)
		{
			if (myMatrix[i][j])
			{
				if ((j + this->posX > 8) && (side == "Right")) {
					return true;
				}
				if ((j + this->posX < 1) && (side == "Left")) {
					return true;
				}
			}
		}
	}
	return false;

}


void FallingShape::rotate(int size)
{
	this->rotation -= 90.0f;
	std::vector<std::vector<bool>>  myMatrix;
	if (size == 3)  myMatrix = { {{false,false,false},{false,false,false},{false,false,false}} };
	if (size == 4)  myMatrix = { {{false,false,false,false},{false,false,false,false},{false,false,false,false}, {false,false,false,false}} };
	assignCoordsToMatrix(myMatrix);
	myMatrix = utility::rotateMatrix(myMatrix);
	fillMyCoordsAsRotatedCoords(myMatrix);

}


void FallingShape::handleKeyLeft()
{


	if (IsKeyPressed(KEY_LEFT) && !checkForCoordsInDanger())
	{
		this->shiftLeft();
		if (CheckForCoordsInSides()) {
			this->shiftRight();
		}
	}


}


void FallingShape::handleKeyRight()
{

	if (IsKeyPressed(KEY_RIGHT) && !checkForCoordsInDanger())
	{
		this->shiftRight();
		if (CheckForCoordsInSides()) {
			this->shiftLeft();
		}
	}


}



void FallingShape::handleKeyUp()
{
	if (!IsKeyPressed(KEY_UP) || this->typeOfShape == 7 || checkForCoordsInDanger()) return;
	if (this->typeOfShape == 1)
	{
		this->rotate(4);
		if (checkForCoordsInCorrupt() || CheckForCoordsInSides()) {
			this->rotate(4);
			this->rotate(4);
			this->rotate(4);
		}
		return;
	}

	this->rotate(3);
	if (checkForCoordsInCorrupt() || CheckForCoordsInSides())
	{
		this->rotate(3);
		this->rotate(3);
		this->rotate(3);
	}

}



void FallingShape::handleKeySpace() {
	if (IsKeyPressed(KEY_SPACE)) {
		PlaySound(texture::boom);

		for (int i = 0; i < 20; i++) {
			if (checkForCoordsInDanger()) return;
			this->shiftDown();
		}
	}
}




void FallingShape::handleUserKeyInputs()
{
	handleKeyLeft();
	handleKeyRight();
	handleKeyUp();
	handleKeySpace();

}


void FallingShape::updateDangerAndCorruptLists()
{
	for (int i = 0; i < this->myCurrCoordsList.size(); i++)
	{
		coordinategrid::addNewCoordsToLists(myCurrCoordsList[i]);
	}
}

void FallingShape::update()
{
	if ((game::frames % 20) == 0 && !checkForCoordsInDanger())
	{
		this->shiftDown();
	}
	this->handleUserKeyInputs();
}



std::string FallingShape::getCoords()
{
	std::string myString = std::to_string(this->posX) + "," + std::to_string(this->posY);
	return myString;

}



int FallingShape::getY()
{
	return this->posY;
}



bool FallingShape::getStuck()
{
	return this->stuck;
}




int FallingShape::calculateDistanceToDrop() {

	//scan through each coord of the block
	//in each cord there is a col, and scan each row of that col, and find distance from the closest danger block below, and that cord. 

	//return the smallest. 

	int currMinDistance = 20;
	for (int i = 0; i < this->myCurrCoordsList.size(); i++) {

		int blockX = this->myCurrCoordsList[i][0];
		int blockY = this->myCurrCoordsList[i][1];

		int dangerY = 0;
		for (int row = blockY; row < 20; row++) {
			if (coordinategrid::isCoordInDanger(std::array<int, 2> {blockX, row})) {
				dangerY = row;
				break;
			}
		}
		if ((dangerY - blockY) < currMinDistance) currMinDistance = (dangerY - blockY);
	}

	return currMinDistance;


}




//draw functions
void FallingShape::draw()
{
	coordinategrid::DrawTextureInCoords(this->myTexture, this->posX, this->posY, this->rotation);

	if (!this->stuck) {
		coordinategrid::DrawTextureInCoords(this->myTextureGhost, this->posX, this->posY + calculateDistanceToDrop(), this->rotation);
	}




}