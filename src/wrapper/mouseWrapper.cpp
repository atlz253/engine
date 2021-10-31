#include "wrapper.hpp"

#include "mouse.hpp"

using namespace engn;

extern "C"
{
    Point MousePosition(void)
    {
        return mouse::Position();
    }

    bool MouseLeftClick(void)
    {
        return mouse::LeftClick();
    }
}