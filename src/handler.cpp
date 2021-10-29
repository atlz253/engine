#include "handler.hpp"

#include <iostream>

#include "event.hpp"
#include "engine.hpp"
#include "exception.hpp"

using namespace engn;

bool GameHandler::init = false;

GameHandler::GameHandler()
{
    if (!init)
        init = true;
    else
        throw DoubleInitException();
    
    scene = nullptr;
}

void GameHandler::Init(int w, int h) // TODO: remove this method
{
    engine::init(w, h);
    events::init();
}

void GameHandler::Start()
{
    Loop();
}

void GameHandler::SetScene(Scene *scene)
{
    this->scene = scene;
}

void GameHandler::Loop()
{
    while (events::check())
    {
        if (scene)
        {
            render::clear();

            scene->Process(scene);
            scene->Render();

            render::present();
        }
    }
}

GameHandler::~GameHandler()
{
    init = false;

    delete scene;
}