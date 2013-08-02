//
// FILE:        JewelFactory.h
// LICENSE:     The MIT license
// PURPOUSE:    Creation of jewel views.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "JewelView.h"

namespace Game
{
    class JewelFactory final
    {
    public:
        enum JewelType
        {
            BLUE,
            GREEN,
            PURPLE,
            RED,
            YELLOW,
            TYPE_COUNT
        };

    public:
                        JewelFactory        ();
                        ~JewelFactory       ();

        JewelView*      createView          ( JewelType type );


        //-------------------------------
        // Private utility functions
    private:
        void            createViewPrototype     ( JewelType type, const char* path );


    private:
        JewelView*      mViewPrototypes [ TYPE_COUNT ];
    };
}
