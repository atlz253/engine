#include "eventManager.hpp"

#include <iostream>

#include "SDL.h"

namespace engn::EventManager
{
    SDL_Event *event;

    bool Init()
    {
        event = new SDL_Event;
        
        return false;
    }

    bool Check(void)
    {
        while (SDL_PollEvent(event))
        {
            switch (event->type)
            {
            case SDL_WINDOWEVENT:
                switch (event->window.event)
                {
                case SDL_WINDOWEVENT_HIDDEN:
                    std::cout << "Window minimize" << std::endl;

                    while (SDL_WaitEvent(event))
                        if (event->window.event == SDL_WINDOWEVENT_SHOWN)
                            break;
                    break;
                }
                break;
            case SDL_QUIT:
                std::cout << "SdlWindow: SDL_Quit event" << std::endl;
                delete event;
                return false;
                break;
            }
        }

        return true;
    }

    void Quit()
    {
        SDL_Event *event = new SDL_Event;
        event->type = SDL_QUIT;
        SDL_PushEvent(event);
    }
}