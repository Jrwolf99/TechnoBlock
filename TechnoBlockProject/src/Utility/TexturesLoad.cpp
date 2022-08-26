

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

    void LoadTextures()
    {
        GameBox = LoadTexture("Assets/GameBox.png");
        BlockOne = LoadTexture("Assets/BlockOne.png");
        BlockTwo = LoadTexture("Assets/BlockTwo.png");
        BlockThree = LoadTexture("Assets/BlockThree.png");
        BlockFour = LoadTexture("Assets/BlockFour.png");
        BlockFive = LoadTexture("Assets/BlockFive.png");
        BlockSix = LoadTexture("Assets/BlockSix.png");
        BlockSeven = LoadTexture("Assets/BlockSeven.png");
    }

}