#include "handler.hpp"

#include <random>
#include <iostream>

#include "time.hpp"
#include "scene.hpp"
#include "texture.hpp"
#include "primitive.hpp"

using namespace engn;

const int size = 800;

#define ZOOM 4
#define TILE 16 * ZOOM

class CloudScene final : public engn::Scene
{
private:
    INT16 frames[3] = {0, 16, 32}, frame = 0, speed;
    Texture *cloud;
    Timer *animationTimer, *moveTimer;

    void Random(void)
    {
        static std::random_device dev;
        static std::mt19937 rng(dev());
        static std::uniform_int_distribution<std::mt19937::result_type> dist(0, 6);
        static std::uniform_int_distribution<std::mt19937::result_type> frame(0, 2);
        static std::uniform_int_distribution<std::mt19937::result_type> speed(10, 50);

        INT16 y = TILE * dist(rng), x = 800; // FIXME: remove &
        SetPosition(x, y);

        this->frame = frame(rng);

        this->speed = speed(rng);
    }

protected:
    void Action(void) override
    {
        if (animationTimer->GetTicks() > 1000)
        {
            if (frame < 2)
                frame++;
            else
                frame = 0;

            cloud->SetTile({0, frames[frame], 64, 16});

            animationTimer->Start();
        }

        if (moveTimer->GetTicks() > speed)
        {

            if (this->GetX() != -TILE * 3)
            {
                INT16 x = this->GetX() - 1, y = this->GetY();
                this->SetPosition(x, y);
            }
            else
            {
                Random();
            }

            moveTimer->Start();
        }
    }

public:
    CloudScene(Scene *scene) : engn::Scene(scene, {0, 0, TILE * 3, TILE})
    {
        animationTimer = new Timer();
        animationTimer->Start();

        moveTimer = new Timer();
        moveTimer->Start();

        Random();

        cloud = new Texture("../res/test/texture/rocky_roads/clouds.png", {0, 0, TILE * 3, TILE}, {0, 0, 64, 16});
        Add(cloud);
    }

    ~CloudScene()
    {
        delete moveTimer;
        delete animationTimer;
    }
};

class WaterScene final : public engn::Scene
{
private:
    INT16 frames[8] = {0, 32, 64, 96, 128, 160, 192, 224}, frame = 0, time = 0;
    Texture *water;
    Timer *timer;

protected:
    void Action(void) override
    {
        if (timer->GetTicks() > 3000)
        {
            if (frame < 7)
                frame++;
            else
                frame = 0;

            water->SetTile({frames[frame], 0, 32, 32});

            timer->Start();
        }
    }

public:
    WaterScene(Scene *scene, Point postion) : engn::Scene(scene, {postion.x, postion.y, TILE * 3, TILE * 3})
    {
        timer = new Timer();
        timer->Start();

        water = new Texture("../res/test/texture/rocky_roads/water_8frames.png", {0, 0, TILE * 3, TILE * 3}, {0, 0, 32, 32});
        Add(water);
    }

    ~WaterScene()
    {
        delete timer;
    }
};

class SunScene final : public engn::Scene
{
private:
    INT16 frames[6] = {0, 32, 64, 96, 128, 160}, frame = 0;
    Texture *sun;
    Timer *timer;

protected:
    void Action(void) override
    {
        if (timer->GetTicks() > 250)
        {
            if (frame < 5)
                frame++;
            else
                frame = 0;

            sun->SetTile({frames[frame], 0, 32, 32});

            timer->Start();
        }
    }

public:
    SunScene(Scene *scene, Point position) : engn::Scene(scene, {position.x, position.y, TILE * 2, TILE * 2})
    {
        timer = new Timer();
        timer->Start();

        sun = new Texture("../res/test/texture/rocky_roads/sun.png", {0, 0, TILE * 2, TILE * 2}, {0, 0, 32, 32});
        Add(sun);
    }

    ~SunScene()
    {
        delete timer;
    }
};

class CoinScene final : public engn::Scene
{
private:
    INT16 tile;
    Timer *timer;
    Texture *money;

protected:
    void Action() override
    {
        if (timer->GetTicks() > 150)
        {
            if (tile != 48)
                tile += 16;
            else
                tile = 0;

            money->SetTile({tile, 0, 16, 16});

            timer->Start();
        }
    }

public:
    CoinScene(Scene *scene, Point position) : engn::Scene(scene, {position.x, position.y, TILE, TILE})
    {
        timer = new Timer();
        timer->Start();

        money = new Texture("../res/test/texture/rocky_roads/coin.png", {0, 0, TILE, TILE}, {0, 0, 16, 16});
        Add(money);

        tile = 0;
    }

    ~CoinScene()
    {
        delete timer;
    }
};

class BouncePadScene final : public engn::Scene
{
private:
    INT16 tile;
    Timer *timer;
    Texture *pad;

protected:
    void Action() override
    {
        if (timer->GetTicks() > 750)
        {
            if (tile != 48)
                tile += 16;
            else
                tile = 0;

            pad->SetTile({tile, 0, 16, 16});

            timer->Start();
        }
    }

public:
    BouncePadScene(Scene *scene, Point position) : engn::Scene(scene, {position.x, position.y, TILE, TILE})
    {
        timer = new Timer();
        timer->Start();

        tile = 0;

        pad = new Texture("../res/test/texture/rocky_roads/bounce_pad.png", {0, 0, TILE, TILE}, {0, 0, 16, 16});
        Add(pad);
    }

    ~BouncePadScene()
    {
        delete timer;
    }
};

class BulletScene final : public engn::Scene
{
private:
    Timer *timer;
    UINT16 frame;
    Texture *wind;

protected:
    void Action() override
    {
        if (timer->GetTicks() > 100)
        {
            if (frame != 64)
                frame += 16;
            else
                frame = 0;
            
            wind->SetTile({frame, 0, 16, 16});

            timer->Start();
        }
        
        SetX(GetX() - 1);
    }

public:
    BulletScene(Scene *scene, Point position) : engn::Scene(scene, {position.x, position.y, TILE*2, TILE})
    {
        timer = new Timer();
        timer->Start();

        Add(new Texture("../res/test/texture/rocky_roads/bullet.png", {0, -20, TILE, TILE}));
        
        frame = 0;
        wind = new Texture("../res/test/texture/rocky_roads/bullet_windtrail.png", {TILE, -15, TILE, TILE}, {0, 0, 16, 16});
        Add(wind);
    }

    ~BulletScene()
    {
        delete timer;
    }
};

class CannonScene final : public engn::Scene
{
private:
    Timer *timer;
    int frame;
    bool fire;
    Texture *canon;

protected:
    void Fire(void)
    {
        parent->Add(new BulletScene(parent, {GetX() - TILE + 24, GetY() + TILE}));
    }

    void Action() override
    {
        if (!fire && timer->GetTicks() > 10000)
        {
            fire = true;
            timer->Start();
        }
        else if (fire && timer->GetTicks() > 500)
        {
            if (frame != 64)
            {
                frame += 32;
            }
            else
            {
                Fire();
                frame = 0;
                fire = false;
            }

            timer->Start();
            canon->SetTile({frame, 0, 32, 32});
        }
    }

public:
    CannonScene(Scene *scene, Point position) : engn::Scene(scene, {position.x, position.y, TILE*2, TILE*2})
    {
        timer = new Timer();
        timer->Start();

        frame = 0;
        fire = false;

        canon = new Texture("../res/test/texture/rocky_roads/cannon.png", {0, 0, TILE*2, TILE*2}, {0, 0, 32, 32});
        Add(canon);
        Fire();
    }

    ~CannonScene()
    {
        delete timer;
    }
};

class MainScene final : public engn::Scene
{
private:
    Scene *activities[3];
protected:
    void Action(void) override
    {
    }

public:
    MainScene(Scene *scene, Rect geometry) : engn::Scene(scene, geometry)
    {
        SetGrid(16 * ZOOM);
        GridHighlight();

        Add(new Rectangle({0, 0, size, size}, {118, 206, 217, 255}, true));
        Add(new Texture("../res/test/texture/rocky_roads/background1.png", {0, TILE * 5, 256 * ZOOM, 128 * ZOOM}));

        Add(new SunScene(this, {TILE * 10, TILE}));

        for (int i = 0; i < 5; i++)
            Add(new CloudScene(this));

        for (int i = 0; i < 5; i++)
            Add(new WaterScene(this, {i * TILE * 3, TILE * 10}));

        Add(new CoinScene(this, {TILE * 6, TILE * 8}));
        Add(new BouncePadScene(this, {TILE * 3, TILE * 9}));
        Add(new Texture("../res/test/texture/rocky_roads/sign.png", {TILE * 8, TILE * 8, TILE, TILE * 2}));
        Add(new CannonScene(this, {TILE * 9, TILE * 3}));

        Add(new Texture("../res/test/texture/rocky_roads/tileset_forest.png", {TILE * 3, TILE * 8, TILE * 6, TILE * 5}, {16, 0, 96, 80}));
        Add(new Texture("../res/test/texture/rocky_roads/tileset_forest.png", {TILE * 9, TILE * 5, TILE * 3, TILE}, {128, 48, 48, 16}));
    }
};

class Main final : public engn::Handler
{
private:
public:
    Main()
    {
        Init(800, 800);
        SetScene(new MainScene(nullptr, {0, 0, size, size}));
    }
};

int main()
{
    Main().Start();

    return 0;
}