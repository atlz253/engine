#include "handler.hpp"

#include <iostream>

#include "event.hpp"
#include "engine.hpp"
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
    engine::init(w, h);
    events::init();
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

Handler::~Handler()
{
    init = false;

    delete scene;
}