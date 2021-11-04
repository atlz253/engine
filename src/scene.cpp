#include "scene.hpp"

#include <list>
#include <iostream>

#include "SDL.h"
#include "global.hpp"
#include "primitive.hpp"

using namespace engn;

struct Scene::scene
{
    SDL_Rect *geometry;
    std::list<IScene *> *scenes;

    UINT8 cellSize; // TODO gridW, gridH
    bool highlight;
};

void Scene::Action(void)
{
    // Do nothing
}

Scene::Scene(Scene *parent, Rect geometry)
{
    this->parent = parent;
    
    data = new struct scene;
    data->scenes = nullptr;

    data->cellSize = 1;
    data->highlight = false;

    data->geometry = new SDL_Rect;
    SetPosition(geometry.x, geometry.y);
    SetSize(geometry.w, geometry.h);
}

INT16 Scene::GetX(void)
{
    return data->geometry->x;
}

void Scene::SetX(INT16 x)
{
    data->geometry->x = x;
}

INT16 Scene::GetY(void)
{
    return data->geometry->y;
}

void Scene::SetY(INT16 y)
{
    data->geometry->y = y;
}

void Scene::SetPosition(INT16 x, INT16 y)
{
    SetX(x);
    SetY(y);
}

UINT16 Scene::GetWidth(void)
{
    return data->geometry->w;
}

void Scene::SetWidth(UINT16 w)
{
    data->geometry->w = w;
}

UINT16 Scene::GetHeight(void)
{
    return data->geometry->h;
}

void Scene::SetHeight(UINT16 h)
{
    data->geometry->h = h;
}

void Scene::SetSize(UINT16 w, UINT16 h)
{
    SetWidth(w);
    SetHeight(h);
}

MouseButtons Scene::MouseDown(void)
{
    return MouseLeftClick; // TODO: realize
}

MouseButtons Scene::MouseUp(void)
{
    return MouseLeftClick; // TODO: realize
}

bool Scene::MouseOver(void)
{
    return false; // TODO: realize
}

bool Scene::MouseOut(void)
{
    return false; // TODO: realize
}

bool Scene::MouseMove(void)
{
    return false; // TODO: realize
}

MouseButtons Scene::Click(void)
{
    return MouseLeftClick; // TODO: realize
}

MouseButtons Scene::DblClick(void)
{
    return MouseLeftClick; // TODO: realize
}

void Scene::Add(IScene *scene)
{
    if (!data->scenes)
        data->scenes = new std::list<IScene *>();

    data->scenes->push_back(scene);
}

void Scene::Clear(void)
{
    if (data->scenes)
    {
        for (IScene *scene : *data->scenes)
            delete scene;

        delete data->scenes;
        data->scenes = nullptr;
    }
}

void Scene::GridHighlight(void)
{
    data->highlight = true;
}

void Scene::SetGrid(UINT8 size)
{
    data->cellSize = size;
}

void Scene::Process(void)
{
    if (data->scenes)
        for (IScene *scene : *data->scenes)
        {
            Scene *s = dynamic_cast<Scene *>(scene); // FIXME: This is not good

            if (s)
                s->Process();
        }

    Action();
}

void Scene::Render(void)
{
    SDL_Rect *rect = nullptr;

    if (parent)
    {
        rect = new SDL_Rect;
        rect->h = data->geometry->h;
        rect->w = data->geometry->w;
        rect->x = (data->geometry->x + parent->GetX());
        rect->y = (data->geometry->y + parent->GetY());
    }

    if (data->scenes)
        for (IScene *scene : *data->scenes)
            if (scene)
            {
                SDL_RenderSetViewport(global::renderer, rect);
                scene->Render();
            }

    if (data->highlight && data->cellSize)
    {
        SDL_RenderSetViewport(global::renderer, rect);

        if (data->cellSize == 1)
        {
            Rectangle rect({0, 0, data->geometry->w, data->geometry->h}, COLOR_BLACK);
            rect.Render();
        }
        else
        {
            Line line({0, 0}, {0, data->geometry->h});

            for (size_t x = data->cellSize; x < data->geometry->w; x += data->cellSize)
            {
                line.SetStart({x, 0});
                line.SetEnd({x, data->geometry->h});
                line.Render();
            }

            for (size_t y = 0; y < data->geometry->h; y += data->cellSize)
            {
                line.SetStart({0, y});
                line.SetEnd({data->geometry->w, y});
                line.Render();
            }
            
        }
    }

    delete rect;
}

Scene::~Scene()
{
    Clear();

    delete data->geometry;
}