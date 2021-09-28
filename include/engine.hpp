#ifndef ENGINE
#define ENGINE

#include "define.hpp"

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

extern "C"
{
	EXPORT bool CSEngineInit();
	EXPORT bool CSEngineQuit();

	EXPORT bool CSRenderClear();
	EXPORT void CSRenderPresent();
}

#endif // ENGINE