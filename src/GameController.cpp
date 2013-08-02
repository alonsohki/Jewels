//
// FILE:        GameController.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Main class that controls the game state.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include "GameController.h"

using namespace Game;

GameController::GameController ( int width, int height )
: mBoard(width, height)
{
}

GameController::~GameController ()
{
}

void GameController::swapJewels ( int x1, int y1, int x2, int y2 )
{
}

bool GameController::update ()
{
    return false;
}
