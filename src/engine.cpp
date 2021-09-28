#include "engine.hpp"

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#include "event.hpp"
#include "global.hpp"
#include "textureManager.hpp"
namespace engine
{
    bool init()
    {
        std::cout << "SdlSubSystem: SDL2 initialization" << std::endl;
        if (SDL_Init(SDL_INIT_VIDEO))
        {
            std::cout << "SDL2 initialization error:" << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        /*
            Не отключать композитор рабочих столов на linux дистрибутивах
        */
        SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");

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
        global::window = SDL_CreateWindow("wall", SDL_WINDOWPOS_CENTERED_MASK, SDL_WINDOWPOS_CENTERED_MASK, SCREEN_WIDTH,
                                          SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
        if (!global::window)
        {
            std::cout << "Failed to create window:" << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        global::renderer = SDL_CreateRenderer(global::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!global::renderer)
            std::cout << "Failed to create renderer:" << SDL_GetError() << std::endl;
        
        events::init();
        textures::init();

        return false;
    }

    bool quit()
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

namespace render
{
    bool clear()
    {
        if (!SDL_RenderClear(global::renderer))
            return false;
        
        return true;
    }

    void present()
    {
        SDL_RenderPresent(global::renderer);
    }
}

extern "C"
{
    EXPORT bool CSEngineInit()
    {
        return engine::init();
    }

    EXPORT bool CSEngineQuit()
    {
        return engine::quit();
    }

    EXPORT bool CSRenderClear()
    {
        return render::clear();
    }

    EXPORT void CSRenderPresent()
    {
        render::present();
    }
}