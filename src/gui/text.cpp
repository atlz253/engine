#include "gui.hpp"

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "global.hpp"

using namespace engn;

struct Font::font // FIXME: remove this ?!#
{
    char *path;
    TTF_Font *font;
    int size;
};

Text::Text(Font *font, char *text, Point position, Color color)
{
    this->font = font;
    this->text = text;

    this->geometry = new Rect;
    this->geometry->x = position.x;
    this->geometry->y = position.y;
    this->geometry->w = 0;
    this->geometry->h = 0;

    this->color = new Color;
    this->color->a = color.a;
    this->color->r = color.r;
    this->color->g = color.g;
    this->color->b = color.b;
}

char *Text::GetText(void)
{
    return text;
}

void Text::SetText(char *text)
{
    this->text = text;
}

UINT16 Text::GetWidth(void)
{
    return geometry->w;
}

UINT16 Text::GetHeight(void)
{
    return geometry->h;
}

INT16 Text::GetX(void)
{
    return geometry->x;
}

void Text::SetX(INT16 &x)
{
    geometry->x = x;
}

INT16 Text::GetY(void)
{
    return geometry->y;
}

void Text::SetY(INT16 &y)
{
    geometry->y = y;
}

void Text::SetPosition(INT16 &x, INT16 &y)
{
    SetX(x);
    SetY(y);
}

void Text::Render(void)
{
    SDL_Texture *texture = nullptr;

    if (!text)
        return;

    SDL_Surface *surf = TTF_RenderUTF8_Blended(font->font->font, text, {color->r, color->g, color->b, color->a});
    if (!surf)
    {
        std::cerr << "Failed to convert text to surface: " << TTF_GetError() << std::endl;
        return;
    }

    texture = SDL_CreateTextureFromSurface(global::renderer, surf);
    SDL_FreeSurface(surf);
    if (!texture)
    {
        std::cerr << "Failed to convert text surface to texture: " << SDL_GetError() << std::endl;
        return;
    }

    int w, h;
    if (TTF_SizeUTF8(font->font->font, text, &w, &h))
    {
        std::cerr << "Failed to get text size: " << TTF_GetError() << std::endl;
        return;
    }

    geometry->w = w;
    geometry->h = h;

    SDL_Rect *rect = new SDL_Rect;
    rect->h = geometry->h;
    rect->w = geometry->w;
    rect->x = geometry->x;
    rect->y = geometry->y;

    SDL_RenderCopy(global::renderer, texture, nullptr, rect);
    
    SDL_DestroyTexture(texture);
    delete rect;
}

Text::~Text()
{
    delete color;
    delete geometry;
}