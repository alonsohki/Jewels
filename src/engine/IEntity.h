//
// FILE:        IEntity.h
// LICENSE:     The MIT license
// PURPOUSE:    Interface for the scene entities.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "Matrix.h"
#include "SDL/SDL.h"

namespace Engine
{
    class IEntity
    {
    public:
        virtual                 ~IEntity        () {}

        virtual void            update          () = 0;
        virtual SDL_Surface*    getSurface      () = 0;
        virtual const Matrixf&  getTransform    () = 0;

        virtual float           getZIndex       () const = 0;
    };
}
