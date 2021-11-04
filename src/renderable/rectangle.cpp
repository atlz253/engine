#include "primitive.hpp"

#include "SDL.h"
#include "global.hpp"

using namespace engn;

Rectangle::Rectangle(Rect rect, Color color, bool fill)
{
    this->rect = new Rect;
    this->color = new Color;

    this->rect->h = rect.h;
    this->rect->w = rect.w;
    this->rect->x = rect.x;
    this->rect->y = rect.y;

    this->color->r = color.r;
    this->color->g = color.g;
    this->color->b = color.b;
    this->color->a = color.a;

    this->fill = fill;
}

INT16 Rectangle::GetX(void)
{
    return rect->x;
}

void Rectangle::SetX(INT16 x)
{
    rect->x = x;
}

INT16 Rectangle::GetY(void)
{
    return rect->y;
}

void Rectangle::SetY(INT16 y)
{
    rect->y = y;
}

void Rectangle::SetPosition(INT16 x, INT16 y)
{
    SetX(x);
    SetY(y);
}

UINT16 Rectangle::GetWidth(void)
{
    return rect->w;
}

void Rectangle::SetWidth(UINT16 w)
{
    rect->w = w;
}

UINT16 Rectangle::GetHeight(void)
{
    return rect->h;
}

void Rectangle::SetHeight(UINT16 h)
{
    rect->h = h;
}

void Rectangle::SetSize(UINT16 w, UINT16 h)
{
    SetWidth(w);
    SetHeight(h);
}

void Rectangle::SetColor(Color color)
{
    this->color->a = color.a;
    this->color->r = color.r;
    this->color->g = color.g;
    this->color->b = color.b;
}

void Rectangle::SetFill(bool fill)
{
    this->fill = fill;
}

void Rectangle::Render(void)
{
    SDL_Rect *rect = new SDL_Rect;
    rect->w = this->rect->w;
    rect->h = this->rect->h;
    rect->x = this->rect->x;
    rect->y = this->rect->y;

    SDL_SetRenderDrawColor(global::renderer, color->r, color->g, color->b, color->a);

    if (fill)
        SDL_RenderFillRect(global::renderer, rect);
    else
        SDL_RenderDrawRect(global::renderer, rect);

    SDL_SetRenderDrawColor(global::renderer, 0, 0, 0, 0);

    delete rect;
}

Rectangle::~Rectangle()
{
    delete rect;
    delete color;
}
