#include "handler.hpp"

#include <iostream>

#include "eventManager.hpp"
#include "core.hpp"
#include "exception.hpp"

using namespace engn;

bool Handler::init = false;

Handler::Handler()
{
    if (!init)
        init = true;
    else
        throw DoubleInitException();
    
    scene = nullptr;
}

void Handler::Init(int w, int h) // TODO: remove this method
{
    Core::Init(w, h);
    EventManager::Init();
}

void Handler::Start()
{
    Loop();
}

void Handler::SetScene(Scene *scene)
{
    this->scene = scene;
}

void Handler::Loop()
{
    while (EventManager::Check())
    {
        if (scene)
        {
            Render::Clear();

            scene->Process();
            scene->Render();

            Render::Present();
        }
    }
}

Handler::~Handler()
{
    init = false;

    delete scene;
}