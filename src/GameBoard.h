//
// FILE:        GameBoard.h
// LICENSE:     The MIT license
// PURPOUSE:    Structure containing the current game state.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "JewelType.h"

namespace Game
{
    class GameBoard
    {
    public:
                    GameBoard       ( int width, int height );
                    ~GameBoard      ();

        void        fillRandomly    ();

        int         getWidth        () const { return mWidth; }
        int         getHeight       () const { return mHeight; }

        JewelType   getJewel        ( int x, int y ) const;
        void        setJewel        ( int x, int y, JewelType type );

    private:
        int         mWidth;
        int         mHeight;
        JewelType*  mJewels;
    };
}
