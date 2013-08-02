//
// FILE:        JewelsGame.cpp
// LICENSE:     The MIT license
// PURPOUSE:    Game runner.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#include "JewelsGame.h"

using namespace Game;

JewelsGame::JewelsGame ()
: mScene(nullptr)
{
}

JewelsGame::~JewelsGame ()
{
}

void JewelsGame::initialize ( Engine::Scene* scene )
{
    mScene = scene;
}

void JewelsGame::update ()
{
}

void JewelsGame::handleClick(int x, int y)
{
    printf("%d %d\n", x, y);
}
