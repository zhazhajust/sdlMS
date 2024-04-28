#pragma once
#include "Entity.h"
#include "wz/Property.hpp"
#include "Core/World.h"

class BackGround : public Entity
{
    BackGround(wz::Node *node, int id, World *world);

    enum 
    {
        NORMAL,
        HTILED,
        VTILED,
        TILED,
        HMOVEA,
        VMOVEA,
        HMOVEB,
        VMOVEB
    };
};
