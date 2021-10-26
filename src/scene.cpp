#include "scene.hpp"

using namespace engn;

Scene::Scene(Rect &geometry)
{
    Init();
    
    scenes = new std::vector<IScene*>();

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
    scenes->push_back(scene);
}

void Scene::Clear(void)
{
    for (IScene *scene : *scenes)
        delete scene;
    
    delete scenes;
    scenes = new std::vector<IScene*>();
}

void Scene::Process(Scene *scene)
{

}

void Scene::Render(void)
{
    for (IScene *scene : *scenes)
        scene->Render();
}

Scene::~Scene()
{
    Clear();

    Destroy();

    delete scenes;
    delete geometry;
}