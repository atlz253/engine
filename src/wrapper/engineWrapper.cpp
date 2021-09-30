#include "wrapper.hpp"

#include "engine.hpp"

extern "C"
{
    EXPORT bool EngineInit()
    {
        return engine::init();
    }

    EXPORT bool EngineQuit()
    {
        return engine::quit();
    }

    EXPORT bool RenderClear()
    {
        return render::clear();
    }

    EXPORT void RenderPresent()
    {
        render::present();
    }
}