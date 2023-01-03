#pragma once

#include "Morkovka2D/Camera.hpp"
#include "World.hpp"

class Level {
public:
    virtual ~Level() = default;
    virtual void start(World *world, Camera *camera) = 0;
};