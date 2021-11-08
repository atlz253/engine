#include "wrapper.hpp"

#include "engine.hpp"

extern "C"
{
    EXPORT bool EngineInit(INT32 w, INT32 h)
    {
        return engn::engine::init(w, h);
    }

    EXPORT bool EngineQuit()
    {
        return engn::engine::quit();
    }

    EXPORT bool RenderClear()
    {
        return engn::render::clear();
    }

    EXPORT void RenderPresent()
    {
        engn::render::present();
    }
}