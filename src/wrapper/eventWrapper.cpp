#include "wrapper.hpp"

#include "eventManager.hpp"

extern "C"
{
    EXPORT bool EventCheck()
    {
        return engn::EventManager::Check();
    }
}