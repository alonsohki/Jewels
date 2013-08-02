//
// FILE:        JewelsGame.h
// LICENSE:     The MIT license
// PURPOUSE:    Game runner.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "engine/Scene.h"
#include "GameController.h"
#include "GameBoardView.h"

namespace Game
{
    class JewelsGame final
    {
    public:
                    JewelsGame      ();
                    ~JewelsGame     ();

        void        initialize      ( Engine::Scene* scene );
        void        update          ();
        void        handleClick     ( int x, int y );

    private:
        GameController  mController;
        GameBoardView   mView;
        Engine::Scene*  mScene;
    };
}
