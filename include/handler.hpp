/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#include "scene.hpp"

namespace engn // TODO: SetScene method
{
    class GameHandler
    {
    private:
        Scene *scene;
        static bool init;

        void Loop(void);

    protected:
        virtual void Init(void);

    public:
        GameHandler();

        virtual void Start(void);

        ~GameHandler();
    };
}
