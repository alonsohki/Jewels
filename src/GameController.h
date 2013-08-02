//
// FILE:        GameController.h
// LICENSE:     The MIT license
// PURPOUSE:    Main class that controls the game state.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "GameBoard.h"
#include "GameEvent.h"
#include "engine/Observable.h"

namespace Game
{
    class GameController : public Engine::Observable<GameController&, const GameEvent&>
    {
    public:
                    GameController      ( int width, int height );
                    ~GameController     ();

        void        swapJewels          ( int x1, int y1, int x2, int y2 );
        bool        update              ();

    private:
        GameBoard   mBoard;
    };
}
