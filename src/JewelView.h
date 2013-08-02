//
// FILE:        JewelView.h
// LICENSE:     The MIT license
// PURPOUSE:    Visualization of jewels.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "engine/IEntity.h"

namespace Game
{
    class JewelView : public Engine::IEntity
    {
        friend class JewelFactory;

    private:
                                JewelView       ( const JewelView& other );
                                JewelView       ( SDL_Surface* bitmap );
    public:
        virtual                 ~JewelView      ();


    public:
        void                    setSelected     ( const bool selected ) { mSelected = selected; }
        bool                    setSelected     () const { return mSelected; }


        //--------------------------------------
        // Private utility methods
    private:
        void                    generateBitmaps ( SDL_Surface* from );

        //--------------------------------------
        // Methods inherited from IEntity
    public:
        virtual void            update          ();
        virtual SDL_Surface*    getSurface      ();

    private:
        SDL_Surface*    mBitmap;
        SDL_Surface*    mBorder;
        bool            mBitmapOwner;
        bool            mSelected;
    };
}
