#ifndef TEXTURE_MANAGER
#define TEXTURE_MANAGER

#include <string>

typedef struct SDL_Texture SDL_Texture;

namespace textures
{
    int init();

    SDL_Texture *&get(std::string path); // TODO: smart pointers

    void clear(std::string path);

    int quit();
}

#endif // TEXTURE_MANAGER