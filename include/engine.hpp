#ifndef ENGINE
#define ENGINE

namespace engine
{
  bool init(); // TODO: flags?

  bool quit();
}

namespace render
{
  bool clear();

  void present();
}

#endif // ENGINE