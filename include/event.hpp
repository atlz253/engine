#ifndef EVENT
#define EVENT

extern "C"
{
    __declspec(dllexport) bool __cdecl CSEventCheck();
}

namespace events
{
    int init();

    bool check(void);

    void quit();
}

#endif // EVENT