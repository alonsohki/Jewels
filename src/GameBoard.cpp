//
// FILE:        GameBoard.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Structure containing the current game state.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include <cstring>
#include "GameBoard.h"
#include <random>

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
    std::random_device rd;
    std::default_random_engine e1(rd());
    e1.seed(10040);
    std::uniform_int_distribution<int> rand_jewel(JewelType::FIRST_JEWEL, JewelType::LAST_JEWEL);

    // Fill randomly
    for ( int j = 0; j < mHeight; ++j )
    {
        for ( int i = 0; i < mWidth; ++i )
        {
            setJewel ( i, j, (JewelType)rand_jewel(e1) );
        }
    }

    // Make sure that we didn't create matches
    for ( int j = 0; j < mHeight-1; ++j )
    {
        for ( int i = 0; i < mWidth-1; ++i )
        {
            auto cur = getJewel(i, j);
            // Are the following two jewels equal?
            if ( cur == getJewel(i+1, j) && cur == getJewel(i+2, j) )
            {
                JewelType newJewel;
                // Find a new random jewel that is different from the current one,
                // and also different from the jewels that it has vertically, so we
                // don't create new vertical matches while replacing.
                auto up = getJewel(i, std::max(0, j-1));
                auto down = getJewel(i, j+1);

                while ( ( newJewel = (JewelType)rand_jewel(e1) ) == cur ||
                        newJewel == up || newJewel == down );
                setJewel(i, j, newJewel);
                cur = newJewel;
            }

            if ( cur == getJewel(i, j+1) && cur == getJewel(i, j+2) )
            {                
                // Same as above, but vertically.
                JewelType newJewel;
                auto left = getJewel(std::max(0, i-1), j);
                auto right = getJewel(i+1, j);

                while ( ( newJewel = (JewelType)rand_jewel(e1) ) == cur ||
                        newJewel == left || newJewel == right );
                setJewel(i, j, newJewel);
            }
        }
    }
}

JewelType GameBoard::getJewel ( int x, int y ) const
{
    return mJewels [ y * mWidth + x ];
}

void GameBoard::setJewel ( int x, int y, JewelType type )
{
    mJewels [ y * mWidth + x ] = type;
}
