//
// FILE:        JewelType.h
// LICENSE:     The MIT license
// PURPOUSE:    Enumeration containing the jewel types.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

namespace Game
{
    enum JewelType
    {
        EMPTY = 0,
        BLUE,
        GREEN,
        PURPLE,
        RED,
        YELLOW,
        TYPE_COUNT,
        FIRST_JEWEL = BLUE,
        LAST_JEWEL = YELLOW
    };
}
