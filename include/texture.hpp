/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#ifndef TEXTURE
#define TEXTURE

#include "scene.hpp"

#include <string>

namespace engn
{
    class Texture final : public IScene, IMovable, IResizeable
    {
    private:
        struct texture;

        struct texture *texture;

    public:
        Texture(std::string path, Rect geometry);

        /* Position methods */
        INT16 GetX(void) override;
        void SetX(INT16 &x) override;

        INT16 GetY(void) override;
        void SetY(INT16 &y) override;

        void SetPosition(INT16 &x, INT16 &y) override;

        /* Size methods */
        UINT16 GetWidth(void) override;
        void SetWidth(UINT16 &w) override;

        UINT16 GetHeight(void) override;
        void SetHeight(UINT16 &h) override;

        void SetSize(UINT16 &w, UINT16 &h) override;

        void Render(void) override;

        ~Texture();
    };
}

#endif // TEXTURE
