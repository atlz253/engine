#include "gui.hpp"

#include <iostream>

#include "SDL_ttf.h"

using namespace engn;

struct Font::font
{
    std::string *path;
    TTF_Font *font;
    int size;
};

Font::Font(std::string path, int size)
{
    font = new struct font;
    font->font = TTF_OpenFont(path.c_str(), size);
    font->size = size;
    font->path = new std::string(path);

    if (!font->font)
        std::cerr << "could not open font: " << TTF_GetError() << std::endl;
}

Font::~Font()
{
    TTF_CloseFont(font->font);
    delete font->path;
    delete font;
}