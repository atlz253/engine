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
    std::string path;
    SDL_Texture *texture;
    struct flip *flip; // TODO: flip
    SDL_Rect *geometry;
    SDL_Rect *tile;
};

Texture::Texture(std::string path, Rect geometry)
{
    data = new struct texture;
    data->path = path;
    data->texture = textures::get(path);

    data->tile = nullptr;
    data->flip = nullptr;

    data->geometry = new SDL_Rect;
    this->SetPosition(geometry.x, geometry.y);
    this->SetSize(geometry.w, geometry.h);
}

Texture::Texture(std::string path, Rect geometry, Rect tile) : Texture::Texture(path, geometry)
{
    this->SetTile(tile);
}

INT16 Texture::GetX(void)
{
    return data->geometry->x;
}

void Texture::SetX(INT16 x)
{
    data->geometry->x = x;
}

INT16 Texture::GetY(void)
{
    return data->geometry->y;
}

void Texture::SetY(INT16 y)
{
    data->geometry->y = y;
}

void Texture::SetPosition(INT16 x, INT16 y)
{
    SetX(x);
    SetY(y);
}

void Texture::ClearTile(void)
{
    if (data->tile)
        delete data->tile;

    data->tile = nullptr;
}

void Texture::SetTile(Rect tile)
{
    if (!data->tile)
        data->tile = new SDL_Rect;

    data->tile->h = tile.h;
    data->tile->w = tile.w;
    data->tile->x = tile.x;
    data->tile->y = tile.y;
}

UINT16 Texture::GetWidth(void)
{
    return data->geometry->w;
}

void Texture::SetWidth(UINT16 w)
{
    data->geometry->w = w;
}

UINT16 Texture::GetHeight(void)
{
    return data->geometry->h;
}

void Texture::SetHeight(UINT16 h)
{
    data->geometry->h = h;
}

void Texture::SetSize(UINT16 w, UINT16 h)
{
    SetWidth(w);
    SetHeight(h);
}

void Texture::Render(void)
{
    SDL_Rect *dst = new SDL_Rect;
    dst->h = data->geometry->h;
    dst->w = data->geometry->w;
    dst->x = data->geometry->x;
    dst->y = data->geometry->y;

    if (SDL_RenderCopy(global::renderer, data->texture, data->tile, dst))
        std::cerr << "Texture render error: " << SDL_GetError() << std::endl;
    
    delete dst;
}

Texture::~Texture()
{
    delete data->flip;
    delete data->geometry;
    delete data;
}