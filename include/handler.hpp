#include "scene.hpp"

class GameHandler
{
private:
    Scene *scene;
    static bool init;

    void Loop(void);
protected:
    virtual void Init(void);
public:
    GameHandler();
    
    virtual void Start(void);

    ~GameHandler();
};