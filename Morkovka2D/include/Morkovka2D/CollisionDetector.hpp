#pragma once

#include "Direction.hpp"
#include "Sprite.hpp"

class CollisionDetector {
public:
    static bool moveAcceptable(Sprite *entity, Direction direction, float amount);
};