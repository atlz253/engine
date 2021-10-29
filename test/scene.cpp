#include "handler.hpp"

#include <iostream>

#include "primitive.hpp"
#include "gui.hpp"

using namespace engn;

class MainScene final : public Scene
{
public:
    MainScene(Rect geometry) : Scene(geometry) 
    {
        std::cout << "MainScene init" << std::endl;

        Add(new Rectangle({0, 0, 800, 800}, {195, 251, 216, 255}, true));
        Add(new Text(new Font("font.ttf", 36), "Scene 1", {0, 0}, {0, 0, 0, 255}));
    }

    ~MainScene() {}
};

class Main final : public GameHandler
{
public:
    Main()
    {
        Init(800, 800);
        SetScene(new MainScene({0, 0, 800, 800}));
    }
};

int main()
{
    Main main;

    main.Start();

    return 0;
}