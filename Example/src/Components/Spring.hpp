#pragma once

#include "Player.hpp"

#include <Morkovka2D/GameObject.hpp>
#include <Morkovka2D/Sprite.hpp>

class Spring : public GameObject, public Sprite {
public:
    Spring(Shader *shader, Player *player);
    void update(double deltaTime) override;

private:
    Player *player;
};