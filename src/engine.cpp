#include "engine.hpp"

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#include "event.hpp"
#include "global.hpp"
#include "textureManager.hpp"

namespace engn::Core
{
    bool Init(INT32 w, INT32 h)
    {
        std::cout << "SdlSubSystem: SDL2 initialization" << std::endl;
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
        {
            std::cout << "SDL2 initialization error:" << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        /*
            Не отключать композитор рабочих столов на linux дистрибутивах
        */
#ifdef __unix__
        SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
#endif

        std::cout << "SdlSubSystem: SDL2_Image initialization" << std::endl;
        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
        {
            std::cout << "SDL2_Image initialization error:" << IMG_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        std::cout << "SdlSubSystem: SDL2_ttf initialization" << std::endl;
        if (TTF_Init())
        {
            std::cout << "SDL2_Image initialization error:" << TTF_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        std::cout << "Creating window" << std::endl;
        global::window = SDL_CreateWindow("engine", SDL_WINDOWPOS_CENTERED_MASK, SDL_WINDOWPOS_CENTERED_MASK, w,
                                          h, SDL_WINDOW_OPENGL);
        if (!global::window)
        {
            std::cout << "Failed to create window:" << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        global::renderer = SDL_CreateRenderer(global::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!global::renderer)
            std::cout << "Failed to create renderer:" << SDL_GetError() << std::endl;
        SDL_SetRenderDrawBlendMode(global::renderer, SDL_BLENDMODE_BLEND); // TODO: read docs about this

        events::init();
        TextureManager::Init();

        return false;
    }

    bool Quit()
    {
        SDL_DestroyWindow(global::window);
        SDL_DestroyRenderer(global::renderer);

        std::cout << "SdlSubSystem: завершение работы SDL2" << std::endl;
        SDL_Quit();

        std::cout << "SdlSubSystem: завершение работы SDL2_Image" << std::endl;
        IMG_Quit();

        std::cout << "SdlSubSystem: завершение работы SDL2_ttf" << std::endl;
        TTF_Quit();

        return false;
    }
}

namespace engn::Render
{
    bool Clear()
    {
        if (!SDL_RenderClear(global::renderer))
            return false;

        return true;
    }

    void Present()
    {
        SDL_RenderPresent(global::renderer);
    }
}
