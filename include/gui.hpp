#include "scene.hpp"

#include <string>

namespace engn
{
    class Font final // TODO: setSize
    {
    private:
        struct font;

        struct font *font;

    public:
        Font(std::string path, int size = 20);

        friend class Text;

        ~Font();
    };

    class Text final : public IScene, IMovable
    {
    private:
        struct text;

        struct text *text;

    public:
        Text(Font *font, std::string text, Point position = {0, 0}, Color color = {255, 255, 255, 255});

        /* Text methods */
        std::string GetText(void);
        void SetText(std::string text);

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
