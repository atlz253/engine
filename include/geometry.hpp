#ifndef GEOMETRY
#define GEOMETRY

#include "type.hpp"

class Line final
{
private:
    Point *_start, *_end;
    Color *_color;

public:
    Line(Point start, Point end, Color color = COLOR_WHITE); // TODO: line stroke

    /* Point functions */

    void SetStart(Point start);
    void SetEnd(Point start);

    // Point GetStart(void);
    // Point GetEnd(void);

    /* Color functions */

    void SetColor(Color color);

    /* Render  */

    void Render(void);

    ~Line();
};

#endif // GEOMETRY