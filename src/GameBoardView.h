//
// FILE:        GameBoardView.h
// LICENSE:     The MIT license
// PURPOUSE:    Game board view.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "engine/IEntity.h"
#include "engine/Rect.h"
#include "engine/Scene.h"
#include "GameEvent.h"
#include "JewelFactory.h"
#include "JewelView.h"

namespace Game
{
    class GameController;

    class GameBoardView : public Engine::IEntity
    {
    public:
                    GameBoardView       ();
                    ~GameBoardView      ();

        void        initialize          ( const Engine::Rect& rect, Engine::Scene* scene, GameController* controller );
        JewelView*  getView             ( int x, int y ) const;
    private:
        void        setView             ( int x, int y, JewelView* view );

    private:
        void        handleGameEvent     ( GameController& controller, const GameEvent& evt );

        //--------------------------------------
        // Methods inherited from IEntity
    public:
        virtual void            update          ();
        virtual SDL_Surface*    getSurface      ();


    private:
        Engine::Rect        mRect;
        Engine::Scene*      mScene;
        GameController*     mController;
        JewelFactory        mFactory;
        JewelView**         mViews;
    };
}