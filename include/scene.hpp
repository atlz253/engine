/*
  MIT License

  Copyright (c) 2021 Fedor Alekseev

  For more information check LICENSE
*/

#ifndef SCENE
#define SCENE

#include <vector>

#include "type.hpp"
#include "common.hpp"

namespace engn
{
    class IScene
    {
    public:
        virtual void Render(void){};

        virtual ~IScene() {}
    };

    class Scene : public IScene, IMovable, IResizeable, IMouseListener
    {
    private:
        Scene *parent;
        Rect *geometry;
        std::vector<IScene *> *scenes;

    public:
        Scene(Scene *scene, Rect geometry);

        /* Position methods */
        INT16 GetX(void) override;
        void SetX(INT16 &x) override;

        INT16 GetY(void) override;
        void SetY(INT16 &y) override;

        void SetPosition(INT16 &x, INT16 &y) override;

        /* Size methods */
        UINT16 GetWidth(void) override;
        void SetWidth(UINT16 &w) override;

        UINT16 GetHeight(void) override;
        void SetHeight(UINT16 &h) override;

        void SetSize(UINT16 &w, UINT16 &h) override;

        /* Mouse methods */
        MouseButtons MouseDown(void) override;
        MouseButtons MouseUp(void) override;

        bool MouseOver(void) override;
        bool MouseOut(void) override;
        bool MouseMove(void) override;

        MouseButtons Click(void) override;
        MouseButtons DblClick(void) override;

        /* SubScenes methods */
        void Add(IScene *scene);
        void Clear(void);

        virtual void Process(void);

        void Render(void) final;

        ~Scene();
    };
}

#endif // SCENE
