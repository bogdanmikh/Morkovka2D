#pragma once

#include <Morkovka2D/GameObject.hpp>
#include <Morkovka2D/Renderer/Shader.hpp>
#include <Morkovka2D/Sprite.hpp>

class Ground : public GameObject, public Sprite {
public:
    Ground(Shader *shader);
    void update(double deltaTime) override;
};