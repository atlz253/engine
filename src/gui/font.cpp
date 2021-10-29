#include "gui.hpp"

#include <iostream>

#include "SDL_ttf.h"

using namespace engn;

struct Font::font
{
    char *path;
    TTF_Font *font;
    int size;
};

Font::Font(char *path, int size)
{
    font = new struct font;
    font->font = TTF_OpenFont(path, size);
    font->size = size;
    font->path = path;

    if (!font->font)
        std::cerr << "could not open font: " << TTF_GetError() << std::endl;
}

Font::~Font()
{
    TTF_CloseFont(font->font);

    delete font;
}