//
// FILE:        FrameCounter.h
// LICENSE:     The MIT license
// PURPOUSE:    Frames per second counter.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include <deque>
#include "SDL/SDL.h"

namespace Engine
{
    class FrameCounter final
    {
        enum
        {
            // We will calculate the average framerate in TIME_ON_AVERAGE seconds
            TIME_ON_AVERAGE = 3
        };

    public:
                    FrameCounter    ();
                    ~FrameCounter   ();

        int         getFPS          ();
        void        addFrame        ();

    private:
        std::deque<Uint32>  mFrames;
        Uint32              mStartTime;
    };
}
