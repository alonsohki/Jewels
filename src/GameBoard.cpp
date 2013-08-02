//
// FILE:        GameBoard.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Structure containing the current game state.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include <cstring>
#include "GameBoard.h"

using namespace Game;

GameBoard::GameBoard ( int width, int height )
: mWidth ( width )
, mHeight ( height )
{
    mJewels = new JewelType [ width * height ];
    memset ( mJewels, JewelType::EMPTY, sizeof(JewelType) * width * height );
}

GameBoard::~GameBoard ()
{
    delete [] mJewels;
}

void GameBoard::fillRandomly ()
{
}

JewelType GameBoard::getJewel ( int x, int y ) const
{
    return mJewels [ y * mWidth + x ];
}

void GameBoard::setJewel ( int x, int y, JewelType type )
{
    mJewels [ y * mWidth + x ] = type;
}
