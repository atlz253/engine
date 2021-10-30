#include "texture.hpp"

#include <iostream>

#include "SDL.h"
#include "global.hpp"
#include "textureManager.hpp"

using namespace engn;

struct flip
{
    Flip flip;
    double angle;
    Point center;
};

struct Texture::texture
{
    char *path;
    SDL_Texture *texture;
    struct flip *flip = nullptr;
    SDL_Rect *geometry;
};

Texture::Texture(char *path, Rect geometry)
{
    texture = new struct texture;
    texture->path = path;
    texture->texture = textures::get(path);

    texture->geometry = new SDL_Rect;
    texture->geometry->w = geometry.w;
    texture->geometry->h = geometry.h;
    texture->geometry->x = geometry.x;
    texture->geometry->y = geometry.y;
}

INT16 Texture::GetX(void)
{
    return texture->geometry->x;
}

void Texture::SetX(INT16 &x)
{
    texture->geometry->x = x;
}

INT16 Texture::GetY(void)
{
    return texture->geometry->y;
}

void Texture::SetY(INT16 &y)
{
    texture->geometry->y = y;
}

void Texture::SetPosition(INT16 &x, INT16 &y)
{
    SetX(x);
    SetY(y);
}

UINT16 Texture::GetWidth(void)
{
    return texture->geometry->w;
}

void Texture::SetWidth(UINT16 &w)
{
    texture->geometry->w = w;
}

UINT16 Texture::GetHeight(void)
{
    return texture->geometry->h;
}

void Texture::SetHeight(UINT16 &h)
{
    texture->geometry->h = h;
}

void Texture::SetSize(UINT16 &w, UINT16 &h)
{
    SetWidth(w);
    SetHeight(h);
}

void Texture::Render(void)
{
    if (SDL_RenderCopy(global::renderer, texture->texture, nullptr, texture->geometry))
        std::cerr << "Texture: render error" << SDL_GetError() << std::endl;
}

Texture::~Texture()
{
    delete texture->flip;
    delete texture->geometry;
    delete texture;
}