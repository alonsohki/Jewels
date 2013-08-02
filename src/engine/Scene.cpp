//
// FILE:        Scene.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Scene management.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include <algorithm>
#include <iterator>
#include "Scene.h"
#include <vector>

using namespace Engine;

Scene::Scene ()
: mBackground(nullptr) 
{
}

Scene::~Scene ()
{
    if ( mBackground != nullptr )
        SDL_FreeSurface(mBackground);
}

void Scene::setBackground ( SDL_Surface* bkg )
{
    mBackground = bkg;
}

void Scene::addEntity ( IEntity* entity )
{
    mEntities.insert ( entity );
}

void Scene::removeEntity ( IEntity* entity )
{
    mEntities.erase ( entity );
}

void Scene::update ()
{
    for ( auto& entity : mEntities )
    {
        entity->update ();
    }
}

void Scene::draw ( SDL_Surface* surface )
{
    // Draw the background, if any.
    if ( mBackground != nullptr )
    {
        SDL_Rect srcRect;
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = mBackground->w;
        srcRect.h = mBackground->h;

        SDL_Rect dstRect;
        dstRect.x = 0;
        dstRect.y = 0;
        dstRect.w = std::min<int>(srcRect.w, surface->w);
        dstRect.h = std::min<int>(srcRect.h, surface->h);

        SDL_LowerBlit(mBackground, &srcRect, surface, &dstRect);
    }

    // Get a vector with the entities sorted by their Z-index
    std::vector<IEntity*> entities;
    entities.resize(mEntities.size());
    std::copy(mEntities.begin(), mEntities.end(), entities.begin());
    std::sort(entities.begin(), entities.end(), [] ( const IEntity* a, const IEntity* b ) { return a->getZIndex() < b->getZIndex(); });

    // Draw every entity
    for ( auto& entity : entities )
    {
        SDL_Surface* entitySurface = entity->getSurface();
        if ( entitySurface != nullptr )
        {
            const vec2i& position = entity->getPosition();
            const vec2i& scale = entity->getScale();

            SDL_Rect srcRect;
            srcRect.x = 0;
            srcRect.y = 0;
            srcRect.w = entitySurface->w;
            srcRect.h = entitySurface->h;

            SDL_Rect dstRect;
            dstRect.x = position[0];
            dstRect.y = position[1];
            dstRect.w = srcRect.w * scale[0];
            dstRect.h = srcRect.h * scale[1];

            SDL_LowerBlit(entitySurface, &srcRect, surface, &dstRect);
        }
    }

    // Update the screen
    SDL_UpdateRect(surface, 0, 0, surface->w, surface->h);
}
