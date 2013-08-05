//
// FILE:        JewelsGame.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Game runner.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include "Config.h"
#include "JewelsGame.h"

using namespace Game;

JewelsGame::JewelsGame ()
: mScene(nullptr)
, mBoard(NUMCOLS, NUMROWS)
{
}

JewelsGame::~JewelsGame ()
{
}

void JewelsGame::initialize ( Engine::Scene* scene )
{
    mScene = scene;
    mBoard.fillRandomly();
    
    // Setup the board view
    Engine::Rect viewRect;
    viewRect.x = BOARD_X;
    viewRect.y = BOARD_Y;
    viewRect.width = BOARD_WIDTH;
    viewRect.height = BOARD_HEIGHT;
    mView.initialize(viewRect, scene, &mBoard);

    mSelection = Engine::vec2i(-1, -1);
}

void JewelsGame::update ( int deltaTime )
{
}

void JewelsGame::handleClick(int x, int y)
{
    int jewelX = (x - BOARD_X) / (BOARD_WIDTH / NUMCOLS);
    int jewelY = (y - BOARD_Y) / (BOARD_HEIGHT / NUMROWS);
    if ( jewelX >= 0 && jewelX < NUMCOLS &&
         jewelY >= 0 && jewelY < NUMROWS )
    {
        if ( mSelection[0] == -1 )
        {
            mSelection = Engine::vec2i(jewelX, jewelY);
            if ( !mView.setJewelSelected(mSelection[0], mSelection[1], true) )
                mSelection = Engine::vec2i(-1, -1);
        }
        else
        {
            int distance = abs(jewelX - mSelection[0]) + abs(jewelY - mSelection[1]);
            if ( distance == 1 )
            {
                swapJewels ( jewelX, jewelY, mSelection[0], mSelection[1], true );
            }
            mView.setJewelSelected(mSelection[0], mSelection[1], false);
            mSelection = Engine::vec2i(-1, -1);
        }
    }
}


void JewelsGame::swapJewels ( int x1, int y1, int x2, int y2, bool doCheckMatch )
{
    GameBoardView::AnimationFinishedDelegate::LambdaType del = [=] ()
    {
        // When finished playing the animation, swap the jewels internally
        auto temp = mBoard.getJewel(x1, y1);
        mBoard.setJewel(x1, y1, mBoard.getJewel(x2, y2));
        mBoard.setJewel(x2, y2, temp);

        if ( doCheckMatch )
        {
            // Did this result into a match?
            const bool match1 = checkMatch(x1, y1);
            const bool match2 = checkMatch(x2, y2);
            if ( !match1 && !match2 )
            {
                // If this move didn't create matches, return the jewels
                // to their original positions.
                swapJewels(x2, y2, x1, y1, false);
            }
        }
    };

    mView.swapJewels(x1, y1, x2, y2, del);
}

void JewelsGame::destroyJewel ( int x, int y )
{
    GameBoardView::AnimationFinishedDelegate::LambdaType del = [=] ()
    {
    };
    mView.destroyJewel(x, y, del);
    mBoard.setJewel(x, y, JewelType::EMPTY);
}

bool JewelsGame::checkMatch ( int x, int y )
{
    auto cur = mBoard.getJewel(x, y);

    // First find the left-most jewel of the same kind
    int left;
    for ( left = x; left > 0 && (mBoard.getJewel(left-1, y) == cur); --left );
    // And then the right-most jewel of the same kind
    int right;
    for ( right = x; right < mBoard.getWidth() && (mBoard.getJewel(right+1, y) == cur); ++right );

    // First find the top-most jewel of the same kind
    int top;
    for ( top = y; top > 0 && (mBoard.getJewel(x, top-1) == cur); --top );
    // And then the bottom-most jewel of the same kind
    int bottom;
    for ( bottom = y; bottom < mBoard.getHeight() && (mBoard.getJewel(x, bottom+1) == cur); ++bottom );

    bool match = false;
    // Got an horizontal match?
    if ( (right-left+1) >= 3 )
    {
        match = true;
        while ( left <= right )
        {
            destroyJewel(left, y);
            ++left;
        }
    }
    // Got a vertical match?
    if ( (bottom-top+1) >= 3 )
    {
        match = true;
        while ( top <= bottom )
        {
            destroyJewel(x, top);
            ++top;
        }
    }

    return match;
}
