#include "time.hpp"

#include "SDL.h"

using namespace engn;

namespace engn::time
{
    UINT32 GetTime(void)
    {
        return SDL_GetTicks();
    }

    void Delay(UINT32 ms)
    {
        SDL_Delay(ms);
    }
}

struct Timer::timer
{
    UINT32 ticks;

    bool start;
    bool pause;
};

Timer::Timer()
{
    data = new struct timer;
    
    data->ticks = 0;

    data->start = false;
    data->pause = false;
}

void Timer::Start(void)
{
    data->start = true;
    data->pause = false;

    data->ticks = SDL_GetTicks();
}

void Timer::Stop(void)
{
    data->start = false;
    data->pause = false;

    data->ticks = 0;
}

bool Timer::IsStarted(void)
{
    return data->start;
}

void Timer::Pause(void)
{
    if (IsStarted() && !IsPaused())
    {
        data->pause = true;

        data->ticks = data->ticks - data->ticks;
    }
}

void Timer::UnPause(void)
{
    if (IsStarted() && IsPaused())
    {
        data->pause = false;

        data->ticks = SDL_GetTicks() - data->ticks;
    }
}

bool Timer::IsPaused(void)
{
    return data->pause;
}

UINT32 Timer::GetTicks(void)
{
    if (!IsStarted())
        return 0;

    if (IsPaused())
        return data->ticks;
    else
        return SDL_GetTicks() - data->ticks;
        
}