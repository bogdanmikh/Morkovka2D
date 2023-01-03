#pragma once

#include <Morkovka2D/GameObject.hpp>
#include <Morkovka2D/Sprite.hpp>

class Tree : public GameObject, public Sprite {
public:
    Tree(Shader *shader);
    void update(double deltaTime) override;
};