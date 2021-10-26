#include "primitive.hpp"

#include "SDL.h"
#include "global.hpp"

using namespace engn;

void Rectangle::Init(void)
{
    rect = new Rect;
    color = new Color;
}

Rectangle::Rectangle(Rect &rect, Color &color)
{
    Init();

    this->rect->h = rect.h;
    this->rect->w = rect.w;
    this->rect->x = rect.x;
    this->rect->y = rect.y;

    this->color->r = color.r;
    this->color->g = color.g;
    this->color->b = color.b;
    this->color->a = color.a;
}

void Rectangle::Render(void)
{
    SDL_Rect *rect = new SDL_Rect;
    rect->w = rect->w;
    rect->h = rect->h;
    rect->x = rect->x;
    rect->y = rect->y;

    SDL_SetRenderDrawColor(global::renderer, color->r, color->g, color->b, color->a);
    SDL_RenderDrawRect(global::renderer, rect);
    SDL_SetRenderDrawColor(global::renderer, 0, 0, 0, 0);

    delete rect;
}

void Rectangle::Destroy(void)
{
    delete rect;
    delete color;
}

Rectangle::~Rectangle()
{
    Destroy();
}