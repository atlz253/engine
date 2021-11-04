#include "handler.hpp"

#include <iostream>

#include "scene.hpp"
#include "event.hpp"
#include "texture.hpp"

using namespace engn;

const int size = 800;

class MainScene final : public engn::Scene
{
private:
    Texture *far[2], *back[2], *fore[2];
    int farFrame = 0, backFrame = 0, foreFrame = 0;

protected:
    void Action() override
    {
        if (farFrame == 3)
        {
            if (far[0]->GetX() != 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    INT16 tmp = far[i]->GetX() + 1;
                    far[i]->SetX(tmp);
                }
            }
            else
            {
                INT16 tmp = -1075;
                far[0]->SetX(tmp);

                tmp = 0;
                far[1]->SetX(tmp);
            }

            farFrame = 0;
        }
        else
        {
            farFrame++;
        }

        if (backFrame == 2)
        {
            if (back[0]->GetX() != 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    INT16 tmp = back[i]->GetX() + 1;
                    back[i]->SetX(tmp);
                }
            }
            else
            {
                INT16 tmp = -1075;
                back[0]->SetX(tmp);

                tmp = 0;
                back[1]->SetX(tmp);
            }

            backFrame = 0;
        }
        else
        {
            backFrame++;
        }

        if (foreFrame == 1)
        {
            if (fore[0]->GetX() != 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    INT16 tmp = fore[i]->GetX() + 1;
                    fore[i]->SetX(tmp);
                }
            }
            else
            {
                events::quit();
            }

            foreFrame = 0;
        }
        else
        {
            foreFrame++;
        }
    }

public:
    MainScene(Scene *scene, Rect geometry) : engn::Scene(scene, geometry)
    {
        far[0] = new Texture("../res/test/texture/cyberpunk-street/far-buildings.png", {-1075, 0, 1075, 800});
        far[1] = new Texture("../res/test/texture/cyberpunk-street/far-buildings.png", {0, 0, 1075, 800});
        Add(far[0]);
        Add(far[1]);

        back[0] = new Texture("../res/test/texture/cyberpunk-street/back-buildings.png", {-1075, 0, 1075, 800});
        back[1] = new Texture("../res/test/texture/cyberpunk-street/back-buildings.png", {0, 0, 1075, 800});
        Add(back[0]);
        Add(back[1]);

        fore[0] = new Texture("../res/test/texture/cyberpunk-street/foreground.png", {-1480, 0, 1480, 800});
        fore[1] = new Texture("../res/test/texture/cyberpunk-street/foreground.png", {0, 0, 1480, 800});
        Add(fore[0]);
        Add(fore[1]);
    }
};

class Main final : public engn::Handler
{
public:
    Main()
    {
        Init(size, size);
        SetScene(new MainScene(nullptr, {0, 0, size, size}));
    }
};

int main()
{
    Main().Start();
    std::cout << "success!" << std::endl;

    return 0;
}