#include "gui.hpp"

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "global.hpp"

using namespace engn;

struct Font::font // FIXME: remove this ?!#
{
    std::string *path;
    TTF_Font *font;
    int size;
};

struct Text::text
{
    Font *font;
    Color *color;
    Rect *geometry;
    std::string string;
};

Text::Text(Font *font, std::string text, Point position, Color color)
{
    this->text = new struct text;

    this->text->font = font;
    this->text->string = text;

    this->text->geometry = new Rect;
    this->text->geometry->x = position.x;
    this->text->geometry->y = position.y;
    this->text->geometry->w = 0;
    this->text->geometry->h = 0;

    this->text->color = new Color;
    this->text->color->a = color.a;
    this->text->color->r = color.r;
    this->text->color->g = color.g;
    this->text->color->b = color.b;
}

std::string Text::GetText(void)
{
    return text->string;
}

void Text::SetText(std::string text)
{
    this->text->string = text;
}

UINT16 Text::GetWidth(void)
{
    return text->geometry->w;
}

UINT16 Text::GetHeight(void)
{
    return text->geometry->h;
}

INT16 Text::GetX(void)
{
    return text->geometry->x;
}

void Text::SetX(INT16 &x)
{
    text->geometry->x = x;
}

INT16 Text::GetY(void)
{
    return text->geometry->y;
}

void Text::SetY(INT16 &y)
{
    text->geometry->y = y;
}

void Text::SetPosition(INT16 &x, INT16 &y)
{
    SetX(x);
    SetY(y);
}

void Text::Render(void) // TODO: static text check
{
    SDL_Texture *texture = nullptr;

    if (!text)
        return;

    SDL_Surface *surf = TTF_RenderUTF8_Blended(text->font->font->font, text->string.c_str(), {text->color->r, text->color->g, text->color->b, text->color->a});
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
    if (TTF_SizeUTF8(text->font->font->font, text->string.c_str(), &w, &h))
    {
        std::cerr << "Failed to get text size: " << TTF_GetError() << std::endl;
        return;
    }
    text->geometry->w = w;
    text->geometry->h = h;

    SDL_Rect *rect = new SDL_Rect{text->geometry->x, text->geometry->y, text->geometry->w, text->geometry->h};

    SDL_RenderCopy(global::renderer, texture, nullptr, rect);

    SDL_DestroyTexture(texture);
    delete rect;
}

Text::~Text()
{
    delete text->color;
    delete text->geometry;
}