//
// FILE:        GameBoardView.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Game board view.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include "GameBoardView.h"
#include "GameController.h"
#include "JewelView.h"

using namespace Game;

GameBoardView::GameBoardView ()
: mScene(nullptr)
, mController(nullptr)
, mViews(nullptr)
{
}

GameBoardView::~GameBoardView ()
{
    if ( mViews != nullptr )
    {
        auto& board = mController->getBoard();

        for ( int j = 0; j < board.getHeight(); ++j )
        {
            for ( int i = 0; i < board.getWidth(); ++i )
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

void GameBoardView::initialize ( const Engine::Rect& rect, Engine::Scene* scene, GameController* controller )
{
    mRect = rect;
    mScene = scene;
    mController = controller;

    auto& board = controller->getBoard ();
    int xGap = rect.width / board.getWidth();
    int yGap = rect.height / board.getHeight();

    mViews = new JewelView*[board.getHeight() * board.getWidth()];

    for ( int j = 0; j < board.getHeight(); ++j )
    {
        for ( int i = 0; i < board.getWidth(); ++i )
        {
            auto jewelType = board.getJewel(i, j);
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
        auto& board = mController->getBoard();
        if ( x >= board.getWidth() || y >= board.getHeight() )
            throw std::out_of_range("x or y");
        return mViews [ x + y * board.getWidth() ];
    }
    return nullptr;
}

void GameBoardView::setView ( int x, int y, JewelView* view )
{
    if ( mViews != nullptr )
    {
        auto& board = mController->getBoard();
        if ( x >= board.getWidth() || y >= board.getHeight() )
            throw std::out_of_range("x or y");
        mViews [ x + y * board.getWidth() ] = view;
    }
}


//--------------------------------------
// Methods inherited from IEntity
void GameBoardView::update ()
{
}

SDL_Surface* GameBoardView::getSurface ()
{
    return nullptr;
}
