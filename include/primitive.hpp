/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#ifndef PRIMITIVE
#define PRIMITIVE

#include "scene.hpp"
#include "type.hpp"

namespace engn
{
    class Rectangle final : public IScene, IMovable, IResizeable
    {
    private:
        Rect *rect; // TODO: struct rectangle
        Color *color;
        bool fill;

    public:
        Rectangle(Rect rect, Color color = {255, 255, 255, 255}, bool fill = false);

        /* Chord methods */
        INT16 GetX(void) override;
        void SetX(INT16 &x) override;

        INT16 GetY(void) override;
        void SetY(INT16 &y) override;

        void SetPosition(INT16 &x, INT16 &y) override;

        /* Position methods */
        UINT16 GetWidth(void) override;
        void SetWidth(UINT16 &w) override;

        UINT16 GetHeight(void) override;
        void SetHeight(UINT16 &h) override;

        void SetSize(UINT16 &w, UINT16 &h) override;

        void SetColor(Color color);
        
        void SetFill(bool &fill);

        void Render(void) override;

        ~Rectangle();
    };

    class Line final : public IScene
    {
    private:
        struct line;

        struct line *data;

    public:
        Line(Point start, Point end, Color color = COLOR_BLACK);

        void SetStart(Point start);
        void SetEnd(Point end);

        void SetColor(Color color);

        void Render(void) override;

        ~Line();
    };
}

#endif // PRIMITIVE
