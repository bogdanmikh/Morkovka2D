#pragma once

#include "World.hpp"
#include "Morkovka2D/Camera.hpp"

class Level {
public:   
    virtual ~Level() = default;
    virtual void start(World* world, Camera* camera) = 0;
};