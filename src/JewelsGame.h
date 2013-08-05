//
// FILE:        JewelsGame.h
// LICENSE:     The MIT license
// PURPOUSE:    Game runner.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "engine/Scene.h"
#include "GameBoard.h"
#include "GameBoardView.h"

namespace Game
{
    class JewelsGame final
    {
    public:
                    JewelsGame      ();
                    ~JewelsGame     ();

        void        initialize      ( Engine::Scene* scene );
        void        update          ( int deltaTime );
        void        handleClick     ( int x, int y );

    private:
        void        swapJewels      ( int x1, int y1, int x2, int y2, bool checkMatch );
        bool        checkMatch      ( int x, int y );

    private:
        GameBoard       mBoard;
        GameBoardView   mView;
        Engine::Scene*  mScene;
        Engine::vec2i   mSelection;
    };
}
