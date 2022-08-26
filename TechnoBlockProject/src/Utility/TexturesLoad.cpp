

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
        GameBox = LoadTexture("resources/images/GameBox.png");
        BlockOne = LoadTexture("resources/images/BlockOne.png");
        BlockTwo = LoadTexture("resources/images/BlockTwo.png");
        BlockThree = LoadTexture("resources/images/BlockThree.png");
        BlockFour = LoadTexture("resources/images/BlockFour.png");
        BlockFive = LoadTexture("resources/images/BlockFive.png");
        BlockSix = LoadTexture("resources/images/BlockSix.png");
        BlockSeven = LoadTexture("resources/images/BlockSeven.png");
    }

}