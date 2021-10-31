/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#ifndef HANDLER
#define HANDLER

#include "scene.hpp"

namespace engn
{
    class Handler
    {
    private:
        Scene *scene;
        static bool init;

        void Loop(void);

    public:
        Handler();

        void Init(int w = 1280, int h = 720); // TODO: flags

        void SetScene(Scene *scene);

        void Start(void);

        ~Handler();
    };
}

#endif // HANDLER
