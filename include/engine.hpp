#ifndef ENGINE
#define ENGINE

#include "define.hpp"

namespace engine
{
  int init(); // TODO: flags?

  int quit();
}

namespace render
{
  int clear();

  void present();
}

extern "C"
{
	EXPORT int CSEngineInit();
	EXPORT int CSEngineQuit();

	EXPORT int CSRenderClear();
	EXPORT void CSRenderPresent();
}

#endif // ENGINE