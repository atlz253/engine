#include "entity.hpp"

#include "define.hpp"

extern "C"
{
    EXPORT Entity *CreateEntity(void)
    {
        return new Entity();
    }

    EXPORT UINT16 GetWidth(Entity *entity)
    {
        return entity->GetWidth();
    }

    EXPORT UINT16 GetHeight(Entity *entity)
    {
        return entity->GetHeight();
    }

    EXPORT void SetWidth(Entity *entity, UINT16 w)
    {
        entity->SetWidth(w);
    }

    EXPORT void SetHeight(Entity *entity, UINT16 h)
    {
        entity->SetHeight(h);
    }

    EXPORT INT16 GetX(Entity *entity)
    {
        return entity->GetX();
    }

    EXPORT INT16 GetY(Entity *entity)
    {
        return entity->GetY();
    }

    EXPORT void SetX(Entity *entity, INT16 x)
    {
        entity->SetX(x);
    }

    EXPORT void SetY(Entity *entity, INT16 y)
    {
        entity->SetY(y);
    }

    EXPORT void SetTexture(Entity *entity, const char* path)
    {
        entity->SetTexture(path);
    }


    EXPORT void RenderEntity(Entity *entity)
    {
        entity->render();
    }

    EXPORT void DeleteEntity(Entity *entity)
    {
        delete entity;
    }
}
