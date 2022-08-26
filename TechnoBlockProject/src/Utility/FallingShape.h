

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
	int posX;
	int posY;
	float rotation = 0.0f;
	bool stuck;

	Vector2 rotationOrigin = {(float)posX, (float)posY};

public:
	FallingShape(int typeOfShape);
	~FallingShape();

	void makeCoords(int coordX, int coordY, std::array<int, 2> &mySubCoord);
	void shiftLeft();
	void shiftRight();
	void shiftDown();
	void rotateTypeOne();
	void rotate();
	void handleUserKeyInputs();
	void updateDangerAndCorruptLists();
	bool checkForCoordsInDanger();
	bool checkForCoordsInCorrupt();
	void update();
	void draw();
	std::string getCoords();
	bool getStuck();

	std::array<std::array<bool, 3>, 3> rotateMatrix(std::array<std::array<bool, 3>, 3> mat);
	std::array<std::array<bool, 4>, 4> rotateMatrixFour(std::array<std::array<bool, 4>, 4> mat);
};
