/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#include "type.hpp"

namespace engn
{
    class IMovable // TODO: comments
    {
    public:
        virtual INT16 GetX(void) = 0;
        virtual void SetX(INT16 &x) = 0;

        virtual INT16 GetY(void) = 0;
        virtual void SetY(INT16 &y) = 0;

        virtual void SetPosition(INT16 &x, INT16 &y) = 0;
    };

    class IResizeable
    {
    public:
        virtual UINT16 GetWidth(void) = 0;
        virtual void SetWidth(UINT16 &w) = 0;

        virtual UINT16 GetHeight(void) = 0;
        virtual void SetHeight(UINT16 &h) = 0;

        virtual void SetSize(UINT16 &w, UINT16 &h) = 0;
    };

    enum MouseButtons
    {
        MouseLeftClick = 1,
        MouseRightClick = 2,
        MouseMiddleClick = 3
    };

    class IMouseListener
    {
    public:
        virtual MouseButtons MouseDown(void) = 0;
        virtual MouseButtons MouseUp(void) = 0;

        // TODO: return chords?
        virtual bool MouseOver(void) = 0;
        virtual bool MouseOut(void) = 0;
        virtual bool MouseMove(void) = 0;

        virtual MouseButtons Click(void) = 0;
        virtual MouseButtons DblClick(void) = 0;
    };
}