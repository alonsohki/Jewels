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
#include "engine/Tween.h"
#include "GameBoard.h"
#include "JewelFactory.h"
#include "JewelView.h"
#include <vector>

namespace Game
{
    class GameController;

    class GameBoardView : public Engine::IEntity
    {
        typedef Engine::Tween<Engine::vec2i>    VectorTween;
        typedef std::vector<VectorTween*>       TweenVector;
    public:
        typedef Engine::FastDelegate<void ()>   AnimationFinishedDelegate;
    private:
        typedef std::vector<AnimationFinishedDelegate>  AnimationFinishedVector;

    public:
                    GameBoardView       ();
                    ~GameBoardView      ();

        bool        setJewelSelected    ( int x, int y, const bool selected );
        bool        getJewelSelected    ( int x, int y ) const;
        void        swapJewels          ( int x1, int y1, int x2, int y2, const AnimationFinishedDelegate& del );
        void        destroyJewel        ( int x, int y, const AnimationFinishedDelegate& del );
        void        initialize          ( const Engine::Rect& rect, Engine::Scene* scene, GameBoard* board );

   private:
        JewelView*  getView             ( int x, int y ) const;
        void        setView             ( int x, int y, JewelView* view );

        //--------------------------------------
        // Methods inherited from IEntity
    public:
        virtual void            update          ( int deltaTime );
        virtual SDL_Surface*    getSurface      ();


    private:
        Engine::Rect            mRect;
        Engine::Scene*          mScene;
        JewelFactory            mFactory;
        JewelView**             mViews;
        GameBoard*              mBoard;
        TweenVector             mTweens;
        AnimationFinishedVector mAnimationFinishedVector;
    };
}