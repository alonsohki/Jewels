//
// FILE:        GameEvent.h
// LICENSE:     The MIT license
// PURPOUSE:    Structure holding a game event.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include <string>

namespace Game
{
    struct GameEvent
    {
        std::string type;
        struct
        {
            int x;
            int y;
        } jewel1;
        struct
        {
            int x;
            int y;
        } jewel2;
    };
};
