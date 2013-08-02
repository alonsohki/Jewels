//
// FILE:        GameBoardView.h
// LICENSE:     The MIT license
// PURPOUSE:    Game board view.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "engine/IEntity.h"

namespace Game
{
    class GameBoardView : public Engine::IEntity
    {
    public:
        GameBoardView ();
        ~GameBoardView ();
    };
}