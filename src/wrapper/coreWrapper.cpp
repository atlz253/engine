#include "wrapper.hpp"

#include "core.hpp"

extern "C"
{
    EXPORT bool EngineInit(INT32 w, INT32 h)
    {
        return engn::Core::Init(w, h);
    }

    EXPORT bool EngineQuit()
    {
        return engn::Core::Quit();
    }

    EXPORT bool RenderClear()
    {
        return engn::Render::Clear();
    }

    EXPORT void RenderPresent()
    {
        engn::Render::Present();
    }
}