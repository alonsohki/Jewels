//
// FILE:        Scene.h
// LICENSE:     The MIT license
// PURPOUSE:    Scene management.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "IEntity.h"
#include <set>

namespace Engine
{
    class Scene
    {
        typedef std::set<IEntity*> EntitySet;

    public:
                        Scene           ();
        virtual         ~Scene          ();

        void            setBackground   ( SDL_Surface* background );

        void            addEntity       ( IEntity* entity );
        void            removeEntity    ( IEntity* entity );

        void            update          ( int deltaTime );
        void            draw            ( SDL_Surface* surface );

    private:
        EntitySet       mEntities;
        SDL_Surface*    mBackground;
    };
}
