#include "type.hpp"

namespace engn
{
    namespace time
    {
        UINT32 GetTime(void);

        void Delay(UINT32 ms);
    }

    class Timer final
    {
    private:
        struct timer;

        struct timer *data;
    
    public:
        Timer();

        void Start(void);
        void Stop(void);
        bool IsStarted(void);

        void Pause(void);
        void UnPause(void);
        bool IsPaused(void);

        UINT32 GetTicks(void);


    };
}