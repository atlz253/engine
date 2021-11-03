#include "primitive.hpp"

#include "SDL.h"
#include "global.hpp"

using namespace engn;

struct Line::line
{
    Point *start;
    Point *end;
    SDL_Color *color;
};

Line::Line(Point start, Point end, Color color)
{
    data = new struct line;
    data->start = nullptr;
    data->end = nullptr;
    data->color = nullptr;


    SetStart(start);
    SetEnd(end);

    SetColor(color);
}

void Line::SetStart(Point start)
{
    if (!data->start)
        data->start = new Point;

    data->start->x = start.x;
    data->start->y = start.y;
}

void Line::SetEnd(Point end)
{
    if (!data->end)
        data->end = new Point;
    
    data->end->x = end.x;
    data->end->y = end.y;
}

void Line::SetColor(Color color)
{
    if (!data->color)
        data->color = new SDL_Color;
    
    data->color->r = color.r;
    data->color->g = color.g;
    data->color->b = color.b;
    data->color->a = color.a;
}

void Line::Render(void)
{
    SDL_SetRenderDrawColor(global::renderer, data->color->r, data->color->g, data->color->b, data->color->a);
    SDL_RenderDrawLine(global::renderer, data->start->x, data->start->y, data->end->x, data->end->y);
    SDL_SetRenderDrawColor(global::renderer, 0, 0, 0, 0);
}

Line::~Line()
{
    delete data->start;
    delete data->end;
    delete data->color;
    delete data;
}