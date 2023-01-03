#pragma once

#include "Player.hpp"
#include <Morkovka2D/Sprite.hpp>

class Money : public GameObject, public Sprite {
public:
    int money = 0;
    int max_money;
    Money(Shader *shader, Player *player);
    void update(double deltaTime) override;

private:
    Player *player;
    float moveSpeed = 0.5f;
};