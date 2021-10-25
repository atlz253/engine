/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#include "scene.hpp"

namespace engn
{
    struct texture;

    class Texture final : IScene
    {
    private:
        struct texture *texture;

    public:
        Texture();

        void Render(void) override;

        ~Texture();
    };
}