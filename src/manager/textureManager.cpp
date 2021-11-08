#include "textureManager.hpp"

#include <map>
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "global.hpp"

namespace engn::TextureManager
{
  std::map<std::string, SDL_Texture *> *dict;

  int Init()
  {
    dict = new std::map<std::string, SDL_Texture *>;

    return 0;
  }

  SDL_Texture *&GetTexture(std::string path)
  {
    if (dict->count(path) == 0)
    {
      std::cout << "TextureManager: load texture " << path << std::endl;
      SDL_Texture *texture = IMG_LoadTexture(global::renderer, path.c_str());

      if (!texture)
        std::cout << "TextureManager: failed to load texture" << IMG_GetError() << std::endl;

      (*dict)[path] = texture;
    }

    return (*dict)[path];
  }

  void Clear(std::string path)
  {
    std::map<std::string, SDL_Texture *>::iterator iterator;

    iterator = dict->find(path);

    if (iterator->first != path)
      return;

    SDL_DestroyTexture(iterator->second);
  }

  int Quit()
  {
    std::map<std::string, SDL_Texture *>::iterator iterator;

    std::cout << "TextureManager: removing textures from memory" << std::endl;
    for (iterator = dict->begin(); iterator != dict->end(); iterator++)
      SDL_DestroyTexture(iterator->second);

    delete dict;

    return 0;
  }
}