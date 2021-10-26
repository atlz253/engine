#include "handler.hpp"

#include <iostream>

#include "exception.hpp"

using namespace engn;

bool GameHandler::init = false;

void GameHandler::Init()
{

}

GameHandler::GameHandler()
{
    Init();

    scene = nullptr;

    if (!init)
    {
        init = true;
    }
    else
    {
        throw DoubleInitException();
    }
}

void GameHandler::Start()
{

}

void GameHandler::Loop()
{
    // TODO: realize
}

GameHandler::~GameHandler()
{
    init = false;

    delete scene;
}