//
// FILE:        GameBoardView.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Game board view.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include "Config.h"
#include "GameBoardView.h"
#include "JewelView.h"

using namespace Game;

GameBoardView::GameBoardView ()
: mScene(nullptr)
, mViews(nullptr)
{
}

GameBoardView::~GameBoardView ()
{
    if ( mViews != nullptr )
    {
        for ( int j = 0; j < mBoard->getHeight(); ++j )
        {
            for ( int i = 0; i < mBoard->getWidth(); ++i )
            {
                auto cur = getView(i, j);
                mScene->removeEntity ( cur );
                delete cur;
            }
        }

        delete [] mViews;
    }

    if ( mScene != nullptr )
        mScene->removeEntity ( this );
}

void GameBoardView::initialize ( const Engine::Rect& rect, Engine::Scene* scene, GameBoard* board )
{
    mRect = rect;
    mScene = scene;
    mBoard = board;

    int xGap = rect.width / mBoard->getWidth();
    int yGap = rect.height / mBoard->getHeight();

    mViews = new JewelView*[mBoard->getHeight() * mBoard->getWidth()];

    for ( int j = 0; j < mBoard->getHeight(); ++j )
    {
        for ( int i = 0; i < mBoard->getWidth(); ++i )
        {
            auto jewelType = mBoard->getJewel(i, j);
            auto jewel = mFactory.createView(jewelType);
            jewel->setPosition(Engine::vec2i(mRect.x + xGap * i, mRect.y + yGap * j));
            mScene->addEntity(jewel);
            setView(i, j, jewel);
        }
    }

    mScene->addEntity ( this );
}

JewelView* GameBoardView::getView ( int x, int y ) const
{
    if ( mViews != nullptr )
    {
        if ( x >= mBoard->getWidth() || y >= mBoard->getHeight() )
            throw std::out_of_range("x or y");
        return mViews [ x + y * mBoard->getWidth() ];
    }
    return nullptr;
}

void GameBoardView::setView ( int x, int y, JewelView* view )
{
    if ( mViews != nullptr )
    {
        if ( x >= mBoard->getWidth() || y >= mBoard->getHeight() )
            throw std::out_of_range("x or y");
        mViews [ x + y * mBoard->getWidth() ] = view;
    }
}

void GameBoardView::swapJewels ( int x1, int y1, int x2, int y2 )
{
    using namespace Engine;

    JewelView* jv1 = getView ( x1, y1 );
    JewelView* jv2 = getView ( x2, y2 );

    auto tween1 = new PositionTween ( TweenType::LINEAR, jv1->getPosition(), jv2->getPosition(), SWAP_INTERVAL, [jv1] ( const vec2i& v ) { jv1->setPosition(v); } );
    auto tween2 = new PositionTween ( TweenType::LINEAR, jv2->getPosition(), jv1->getPosition(), SWAP_INTERVAL, [jv2] ( const vec2i& v ) { jv2->setPosition(v); } );

    mTweens.push_back(tween1);
    mTweens.push_back(tween2);
}


//--------------------------------------
// Methods inherited from IEntity
void GameBoardView::update ( int deltaTime )
{
    TweenVector newTweens;
    for ( auto tween : mTweens )
    {
        tween->update ( deltaTime );
        if ( tween->hasFinished() == false )
            newTweens.push_back(tween);
        else
            delete tween;
    }
    mTweens = newTweens;
}

SDL_Surface* GameBoardView::getSurface ()
{
    return nullptr;
}
