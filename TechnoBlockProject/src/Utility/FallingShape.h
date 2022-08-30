

#pragma once

#include "raylib.h"
#include <iostream>
#include <vector>
#include <array>
#include <string>

class FallingShape
{
private:
	int typeOfShape;
	std::vector<std::array<int, 2>> myCurrCoordsList;

	Texture2D myTexture;
	Texture2D myTextureGhost;
	int posX;
	int posY;
	float rotation = 0.0f;
	bool stuck;

	Vector2 rotationOrigin = { (float)posX, (float)posY };

public:

	FallingShape(int typeOfShape);
	~FallingShape();

	void makeCoords(int coordX, int coordY, std::array<int, 2>& mySubCoord);
	void shiftLeft();
	void shiftRight();
	void shiftDown();

	bool CheckForCoordsInSides();
	bool checkForCoordsInDanger();
	bool checkForCoordsInCorrupt();
	void assignCoordsToMatrix(std::vector<std::vector<bool>>& myMatrix);
	void fillMyCoordsAsRotatedCoords(std::vector<std::vector<bool>> myMatrix);
	bool isHittingEdge(std::string side, std::vector<std::vector<bool>> myMatrix);
	void rotate(int size);

	void handleKeyLeft();
	void handleKeyRight();
	void handleKeyUp();
	void handleKeySpace();
	void handleUserKeyInputs();

	void updateDangerAndCorruptLists();
	void update();

	int calculateDistanceToDrop();
	void draw();

	std::string getCoords();
	int getY();
	bool getStuck();

	std::array<std::array<bool, 3>, 3> rotateMatrix(std::array<std::array<bool, 3>, 3> mat);
	std::array<std::array<bool, 4>, 4> rotateMatrixFour(std::array<std::array<bool, 4>, 4> mat);
};
