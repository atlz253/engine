/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#ifndef EXCEPTION
#define EXCEPTION

#include <exception>

namespace engn
{
  class DoubleInitException final : std::exception
  {
  public:
    DoubleInitException(){};
    ~DoubleInitException(){};

    const char *what(void) const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
  };
}

#endif // EXCEPTION
