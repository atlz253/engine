#ifndef TYPE
#define TYPE

#include <cstdint>

#define INT16 std::int16_t
#define INT32 std::int32_t

#define UINT16 std::uint16_t

typedef struct Rect
{
    INT16 x, y;
    UINT16 w, h;
} Rect;

typedef struct Point
{
    int x;
    int y;
} Point;

typedef struct SDL_Texture Texture;

typedef struct SDL_Color Color;

typedef enum
{
    FLIP_NONE = 0,
    FLIP_HORIZONTAL = 1,
    FLIP_VERTICAL = 2
} Flip;

typedef struct _TTF_Font Font;

#endif // TYPE