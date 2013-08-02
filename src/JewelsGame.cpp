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
, mController(NUMCOLS, NUMROWS)
{
}

JewelsGame::~JewelsGame ()
{
}

void JewelsGame::initialize ( Engine::Scene* scene )
{
    mScene = scene;
    mController.initialize ();
    
    // Setup the board view
    Engine::Rect viewRect;
    viewRect.x = BOARD_X;
    viewRect.y = BOARD_Y;
    viewRect.width = BOARD_WIDTH;
    viewRect.height = BOARD_HEIGHT;
    mView.initialize(viewRect, scene, &mController);
}

void JewelsGame::update ()
{
}

void JewelsGame::handleClick(int x, int y)
{
    printf("%d %d\n", x, y);
}
