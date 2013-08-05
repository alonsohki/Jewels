//
// FILE:        JewelsGame.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Game runner.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include "Config.h"
#include "JewelsGame.h"

using namespace Game;

JewelsGame::JewelsGame ()
: mScene(nullptr)
, mBoard(NUMCOLS, NUMROWS)
{
}

JewelsGame::~JewelsGame ()
{
}

void JewelsGame::initialize ( Engine::Scene* scene )
{
    mScene = scene;
    mBoard.fillRandomly();
    
    // Setup the board view
    Engine::Rect viewRect;
    viewRect.x = BOARD_X;
    viewRect.y = BOARD_Y;
    viewRect.width = BOARD_WIDTH;
    viewRect.height = BOARD_HEIGHT;
    mView.initialize(viewRect, scene, &mBoard);

    mSelection = Engine::vec2i(-1, -1);
}

void JewelsGame::update ( int deltaTime )
{
}

void JewelsGame::handleClick(int x, int y)
{
    int jewelX = (x - BOARD_X) / (BOARD_WIDTH / NUMCOLS);
    int jewelY = (y - BOARD_Y) / (BOARD_HEIGHT / NUMROWS);
    if ( jewelX >= 0 && jewelX < NUMCOLS &&
         jewelY >= 0 && jewelY < NUMROWS )
    {
        if ( mSelection[0] == -1 )
        {
            mSelection = Engine::vec2i(jewelX, jewelY);
            mView.setJewelSelected(mSelection[0], mSelection[1], true);
        }
        else
        {
            int distance = abs(jewelX - mSelection[0]) + abs(jewelY - mSelection[1]);
            if ( distance == 1 )
            {
                mView.swapJewels(jewelX, jewelY, mSelection[0], mSelection[1]);
            }
            mView.setJewelSelected(mSelection[0], mSelection[1], false);
            mSelection = Engine::vec2i(-1, -1);
        }
    }
}
