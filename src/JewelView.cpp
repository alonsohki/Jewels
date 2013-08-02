//
// FILE:        JewelView.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Visualization of jewels.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include "JewelView.h"

using namespace Game;

JewelView::JewelView ( const JewelView& other )
: mBitmap(other.mBitmap)
, mBorder(other.mBorder)
, mBitmapOwner(false)
, mSelected(false)
{
}

JewelView::JewelView ( SDL_Surface* bitmap )
: mBitmap(nullptr)
, mBorder(nullptr)
, mBitmapOwner(true)
, mSelected(false)
{
    generateBitmaps(bitmap);
}

JewelView::~JewelView ()
{
    if ( mBitmapOwner )
    {
        SDL_FreeSurface(mBitmap);
        SDL_FreeSurface(mBorder);
    }
}

//--------------------------------------
// Private utility methods
void JewelView::generateBitmaps ( SDL_Surface* from )
{
    mBitmapOwner = true;

    // Create a surface with 2 extra border pixels, and copy the source surface to it.
    mBitmap = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCALPHA, from->w + 4, from->h + 4,
                                   from->format->BitsPerPixel, from->format->Rmask, from->format->Gmask, from->format->Bmask, from->format->Amask);

    SDL_Rect srcRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = from->w;
    srcRect.h = from->h;

    SDL_Rect dstRect;
    dstRect.x = 2;
    dstRect.y = 2;
    dstRect.w = from->w - 4;
    dstRect.h = from->h - 4;
    SDL_SetAlpha(from, 0, 0);
    SDL_BlitSurface(from, &srcRect, mBitmap, &dstRect);

    // Clone it for the border surface
    mBorder = SDL_ConvertSurface(mBitmap, mBitmap->format, SDL_HWSURFACE);

    // Create a white border around the jewel
    for ( int j = 0; j < mBorder->h; ++j )
    {
        for ( int i = 0; i < mBorder->w; ++i )
        {
            // Is it a transparent pixel? Then check if we should draw a border
            if ( (SDL_GetPixel(mBitmap, i, j) & 0xff000000) == 0 )
            {
                bool anyPixel = false;
                for ( int y = -2; !anyPixel && y <= 2; ++y )
                {
                    for ( int x = -2; !anyPixel && x <= 2; ++x )
                    {
                        if ( SDL_GetPixel(mBitmap, clamp(0, i+x, mBitmap->w-1), clamp(0, j+y, mBitmap->h-1)) != 0 )
                            anyPixel = true;
                    }
                }

                if ( anyPixel )
                    SDL_PutPixel(mBorder, i, j, 0x88ffffff);
            }
        }
    }
}


//--------------------------------------
// Methods inherited from IEntity
void JewelView::update ()
{
}

SDL_Surface* JewelView::getSurface ()
{
    return mSelected ? mBorder : mBitmap;
}
