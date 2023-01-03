#pragma once

#include <Morkovka2D/GameObject.hpp>
#include <Morkovka2D/Sprite.hpp>
#include "Player.hpp"

class GameOverLabel: public GameObject, public Sprite {
public:
    GameOverLabel(Shader* shader, Player* player);
    void update(double deltaTime) override;
private:
    double labelTime;
};