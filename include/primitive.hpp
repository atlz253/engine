/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#include "scene.hpp"
#include "type.hpp"

namespace engn
{
    class Rectangle final : IScene
    {
    private:
        Rect *rect;
        Color *color;

        void Init(void) override;
        void Destroy(void) override;

    public:
        Rectangle(Rect &rect, Color &color); // TODO: standart parametrs

        void Render(void) override;

        ~Rectangle();
    };

    class Line final : IScene
    {
    private:
        Point *start;
        Point *end;
        Color *color;

        void Init(void) override;
        void Destroy(void) override;

    public:
        Line(Point &start, Point &end);

        void Render(void) override;

        ~Line();
    };
}
