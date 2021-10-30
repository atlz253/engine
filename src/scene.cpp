#include "scene.hpp"

#include <iostream>

#include "SDL.h"
#include "global.hpp"

using namespace engn;

Scene::Scene(Scene *scene, Rect geometry)
{
    parent = scene;
    scenes = nullptr;

    this->geometry = new Rect;
    this->geometry->h = geometry.h;
    this->geometry->w = geometry.w;
    this->geometry->x = geometry.x;
    this->geometry->y = geometry.y;
}

INT16 Scene::GetX(void)
{
    return geometry->x;
}

void Scene::SetX(INT16 &x)
{
    geometry->x = x;
}

INT16 Scene::GetY(void)
{
    return geometry->y;
}

void Scene::SetY(INT16 &y)
{
    geometry->y = y;
}

void Scene::SetPosition(INT16 &x, INT16 &y)
{
    SetX(x);
    SetY(y);
}

UINT16 Scene::GetWidth(void)
{
    return geometry->w;
}

void Scene::SetWidth(UINT16 &w)
{
    geometry->w = w;
}

UINT16 Scene::GetHeight(void)
{
    return geometry->h;
}

void Scene::SetHeight(UINT16 &h)
{
    geometry->h = h;
}

void Scene::SetSize(UINT16 &w, UINT16 &h)
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
    if (!scenes)
        scenes = new std::vector<IScene *>();

    scenes->push_back(scene);
}

void Scene::Clear(void)
{
    if (scenes)
    {
        for (IScene *scene : *scenes)
            delete scene;

        delete scenes;
        scenes = nullptr;
    }
}

void Scene::Process(void)
{
}

void Scene::Render(void)
{
    SDL_Rect *rect = nullptr;

    if (parent)
    {
        rect = new SDL_Rect;
        rect->h = geometry->h;
        rect->w = geometry->w;
        rect->x = geometry->x + parent->GetX();
        rect->y = geometry->y + parent->GetY();
    }

    SDL_RenderSetViewport(global::renderer, rect);

    if (scenes)
        for (IScene *scene : *scenes)
            if (scene)
                scene->Render();

    delete rect;
}

Scene::~Scene()
{
    Clear();

    delete geometry;
}