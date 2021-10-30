#include "handler.hpp"

#include <random>
#include <iostream>
#include <thread>
#include <chrono>

#include "gui.hpp"
#include "event.hpp"
#include "primitive.hpp"

using namespace engn;

const INT16 size = 800;

class MainScene : public Scene
{
private:
    bool render = false;

public:
    MainScene(Scene *scene, Rect geometry) : Scene(scene, geometry)
    {
        Font *font = new Font("font.ttf", 36);

        Add(new Rectangle({0, 0, 800, 800}, {254, 214, 188, 255}, true));
        Add(new Text(font, "1", {0, 0}, {0, 0, 0, 255}));

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                Scene *child;

                child = new Scene(this, {20 + 380 * i, 20 + 380 * j, 380, 380});
                child->Add(new Rectangle({0, 0, 380, 380}, {255, 250, 221, 200}, true));
                child->Add(new Rectangle({0, 0, 380, 380}, {219, 88, 86, 200}));
                child->Add(new Text(font, "2", {5, 5}, {0, 0, 0, 255}));
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++)
                    {
                        Scene *subchild;

                        subchild = new Scene(child, {20 + 170 * k, 20 + 170 * l, 170, 170});
                        subchild->Add(new Rectangle({0, 0, 170, 170}, {222, 247, 254, 200}, true));
                        subchild->Add(new Rectangle({0, 0, 170, 170}, {198, 216, 255, 200}));
                        subchild->Add(new Text(font, "3", {5, 5}, {0, 0, 0, 255}));

                        child->Add(subchild);
                    }

                Add(child);
            }
    }

    void Process() override
    {
        if (!render)
        {
            render = true;
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::nanoseconds(5000000000));
            events::quit();
        }
    }

    ~MainScene() {}
};

class Main final : public Handler
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
    std::cout << "Scenes succesfully rendered!" << std::endl;

    return 0;
}