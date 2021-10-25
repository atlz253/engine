#include "scene.hpp"

struct texture;

class Texture final: Scene
{
private:
    struct texture *texture;
public:
    Texture();

    void Render(void) override;

    ~Texture();
};