//
// FILE:        JewelFactory.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Creation of jewel views.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include "JewelFactory.h"
#include "SDL/SDL_Image.h"

using namespace Game;

namespace
{
    const char* sViewPaths [] =
    {
        "img/Blue.png",
        "img/Green.png",
        "img/Purple.png",
        "img/Red.png",
        "img/Yellow.png"
    };
};

JewelFactory::JewelFactory ()
{
    for ( int i = 0; i < NUMELEMS(mViewPrototypes); ++i )
        mViewPrototypes[i] = nullptr;
}

JewelFactory::~JewelFactory ()
{
    for ( auto& prototype : mViewPrototypes )
        delete prototype;
}

JewelView* JewelFactory::createView ( JewelType type )
{
    if ( mViewPrototypes[type] == nullptr )
    {
        SDL_Surface* bitmap = IMG_Load(sViewPaths[type]);
        mViewPrototypes[type] = new JewelView(bitmap);
        SDL_FreeSurface(bitmap);
    }
    return new JewelView(*mViewPrototypes[type]);
}
