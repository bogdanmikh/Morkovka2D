#pragma once

#include <Morkovka2D/GameObject.hpp>
#include <Morkovka2D/Sprite.hpp>

class Menu : public GameObject {
public:
    void update(double deltaTime) override;
};