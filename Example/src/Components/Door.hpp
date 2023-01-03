#pragma once

#include "Player.hpp"
#include <Morkovka2D/GameObject.hpp>
#include <Morkovka2D/Renderer/Shader.hpp>
#include <Morkovka2D/Sprite.hpp>

class Door : public GameObject, public Sprite {
public:
    Door(Shader *shader, Player *player);
    void update(double deltaTime) override;

private:
    Player *player;
};