#include "scene.hpp"

namespace engn
{
    class Font final // TODO: setSize
    {
    private:
        struct font;

        struct font *font;

    public:
        Font(char *path, int size = 20);

        friend class Text;

        ~Font();
    };

    class Text final : public IScene, IMovable
    {
    private: // TODO: struct text
        Font *font;
        Color *color;
        char *text;
        Rect *geometry;

    public:
        Text(Font *font, char *text, Point position = {0, 0}, Color color = {255, 255, 255, 255});

        /* Text methods */
        char *GetText(void);
        void SetText(char *text);

        UINT16 GetWidth(void);
        UINT16 GetHeight(void);

        /* Position methods */
        INT16 GetX(void) override;
        void SetX(INT16 &x) override;

        INT16 GetY(void) override;
        void SetY(INT16 &y) override;

        void SetPosition(INT16 &x, INT16 &y) override;

        void Render(void) override;

        ~Text();
    };
}
