#ifndef TEXTURE_MANAGER
#define TEXTURE_MANAGER

#include <string>

typedef struct SDL_Texture SDL_Texture;

namespace engn
{
    namespace TextureManager
    {
        int Init();

        SDL_Texture *&GetTexture(std::string path); // TODO: smart pointers

        void Clear(std::string path);

        int Quit();
    }
}

#endif // TEXTURE_MANAGER