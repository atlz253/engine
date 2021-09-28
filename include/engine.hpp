#ifndef ENGINE
#define ENGINE

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
	__declspec(dllexport) int __cdecl CSEngineInit();
	__declspec(dllexport) int __cdecl CSEngineQuit();

	__declspec(dllexport) int __cdecl CSRenderClear();
	__declspec(dllexport) void __cdecl CSRenderPresent();
}

#endif // ENGINE