//
// FILE:        IEntity.h
// LICENSE:     The MIT license
// PURPOUSE:    Interface for the scene entities.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "Vector.h"
#include "SDL/SDL.h"

namespace Engine
{
    class IEntity
    {
    public:
                                    IEntity         () : mZIndex(0), mPosition(0, 0), mScale(1, 1) {}
        virtual                     ~IEntity        () {}

        virtual void                update          () = 0;
        virtual SDL_Surface*        getSurface      () = 0;

        float                       getZIndex       () const { return mZIndex; }
        const vec2i&                getPosition     () const { return mPosition; }
        const vec2i&                getScale        () const { return mScale; }
        void                        setZIndex       ( const float& idx ) { mZIndex = idx; }
        void                        setPosition     ( const vec2i& pos ) { mPosition = pos; }
        void                        setScale        ( const vec2i& scale ) { mScale = scale; }

    private:
        float   mZIndex;
        vec2i   mPosition;
        vec2i   mScale;
    };
}
