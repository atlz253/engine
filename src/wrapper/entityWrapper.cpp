#include "wrapper.hpp"

#include "entity.hpp"

extern "C"
{
    EXPORT Entity *CreateEntity(void)
    {
        return new Entity();
    }

    EXPORT UINT16 GetWidthEntity(Entity *entity)
    {
        return entity->GetWidth();
    }

    EXPORT UINT16 GetHeightEntity(Entity *entity)
    {
        return entity->GetHeight();
    }

    EXPORT void SetWidthEntity(Entity *entity, UINT16 w)
    {
        entity->SetWidth(w);
    }

    EXPORT void SetHeightEntity(Entity *entity, UINT16 h)
    {
        entity->SetHeight(h);
    }

    EXPORT INT16 GetXEntity(Entity *entity)
    {
        return entity->GetX();
    }

    EXPORT INT16 GetYEntity(Entity *entity)
    {
        return entity->GetY();
    }

    EXPORT void SetXEntity(Entity *entity, INT16 x)
    {
        entity->SetX(x);
    }

    EXPORT void SetYEntity(Entity *entity, INT16 y)
    {
        entity->SetY(y);
    }

    EXPORT UINT16 GetTileWEntity(Entity *entity)
    {
        return entity->GetTileW();
    }

    EXPORT UINT16 GetTileHEntity(Entity *entity)
    {
        return entity->GetTileH();
    }

    EXPORT void SetTileWEntity(Entity *entity, UINT16 w)
    {
        entity->SetTileW(w);
    }

    EXPORT void SetTileHEntity(Entity *entity, UINT16 h)
    {
        entity->SetTileH(h);
    }

    EXPORT INT16 GetTileXEntity(Entity *entity)
    {
        return entity->GetTileX();
    }

    EXPORT INT16 GetTileYEntity(Entity *entity)
    {
        return entity->GetTileY();
    }

    EXPORT void SetTileXEntity(Entity *entity, INT16 x)
    {
        entity->SetTileX(x);
    }

    EXPORT void SetTileYEntity(Entity *entity, INT16 y)
    {
        entity->SetTileY(y);
    }

    EXPORT void SetTextureEntity(Entity *entity, const char* path)
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
