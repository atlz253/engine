/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#ifndef KEYBORAD
#define KEYBORAD

#include <iostream>

typedef enum
{
    SCANCODE_Q = 20,
    SCANCODE_RIGHTBRACKET = 48
} scancode;

typedef const uint8_t *keys;

namespace keyboard
{
    keys state(int *numkeys);
}

#endif // KEYBORAD