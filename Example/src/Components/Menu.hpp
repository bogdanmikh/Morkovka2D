#pragma once

#include <Morkovka2D/Sprite.hpp>
#include <Morkovka2D/GameObject.hpp>

class Menu: public GameObject {
public:
    void update(double deltaTime) override;
};