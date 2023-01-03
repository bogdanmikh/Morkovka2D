#pragma once

#include "Sprite.hpp"
#include "Direction.hpp"

class CollisionDetector {
public:
    static bool moveAcceptable(Sprite* entity, Direction direction, float amount);
};