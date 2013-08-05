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
}

void JewelsGame::update ( int deltaTime )
{
}

void JewelsGame::handleClick(int x, int y)
{
    printf("%d %d\n", x, y);
    mView.swapJewels(0, 0, 0, 1);
}
