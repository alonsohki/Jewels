//
// FILE:        FrameCounter.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Frames per second counter.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include "FrameCounter.h"
#include "SDL/SDL.h"

using namespace Engine;

FrameCounter::FrameCounter ()
{
    mStartTime = SDL_GetTicks();
}

FrameCounter::~FrameCounter ()
{
}

void FrameCounter::addFrame ()
{
    auto now = SDL_GetTicks();

    // Delete frames older than TIME_ON_AVERAGE
    if ( now > (1000*TIME_ON_AVERAGE) )
    {
        auto limit = now - (1000*TIME_ON_AVERAGE);
        while ( mFrames.size() > 0 && (mFrames.front() <= limit) )
            mFrames.pop_front();
    }
    mFrames.push_back(now);
}

int FrameCounter::getFPS ()
{
    auto now = SDL_GetTicks();

    // Delete frames older than TIME_ON_AVERAGE
    if ( now > (1000*TIME_ON_AVERAGE) )
    {
        auto limit = now - (1000*TIME_ON_AVERAGE);
        while ( mFrames.size() > 0 && (mFrames.front() <= limit) )
            mFrames.pop_front();
    }

    return mFrames.size() / TIME_ON_AVERAGE;
}
