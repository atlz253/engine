#ifndef GLOBAL
#define GLOBAL

namespace engn
{
    typedef struct SDL_Window SDL_Window;
    typedef struct SDL_Renderer SDL_Renderer;

    namespace global
    {
        extern SDL_Window *window;
        extern SDL_Renderer *renderer;
    }
}

#endif // GLOBAL