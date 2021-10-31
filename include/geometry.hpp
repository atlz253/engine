/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#ifndef GEOMETRY
#define GEOMETRY

#include "type.hpp"

class Line final // TODO: remove
{
private:
    Point *_start, *_end;
    Color *_color;

public:
    Line(Point start, Point end, Color color = COLOR_WHITE); // TODO: line stroke

    /* Point methods */

    void SetStart(Point start);
    void SetEnd(Point start);

    // Point GetStart(void);
    // Point GetEnd(void);

    /* Color methods */

    void SetColor(Color color);

    /* Render methods */

    void Render(void);

    ~Line();
};

#endif // GEOMETRY
