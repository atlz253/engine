/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#ifndef HANDLER
#define HANDLER

#include "scene.hpp"

namespace engn // TODO: SetScene method
{
    class GameHandler
    {
    private:
        Scene *scene;
        static bool init;

        void Loop(void);

    public:
        GameHandler();

        void Init(int w = 1280, int h = 720); // TODO: flags

        void SetScene(Scene *scene);

        void Start(void);

        ~GameHandler();
    };
}

#endif // HANDLER
