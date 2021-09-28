#ifndef EVENT
#define EVENT

#include "define.hpp"

extern "C"
{
    EXPORT bool CSEventCheck();
}

namespace events
{
    bool init();

    bool check(void);

    void quit();
}

#endif // EVENT