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