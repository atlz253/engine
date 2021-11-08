/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#ifndef ENGINE
#define ENGINE

#include "type.hpp"

namespace engn
{
  namespace Core
  {
    bool Init(INT32 w = 1280, INT32 h = 720); // TODO: flags? + window name

    bool Quit();
  }

  namespace Render
  {
    bool Clear();

    void Present();
  }
}

#endif // ENGINE
