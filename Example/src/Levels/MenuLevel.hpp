#pragma once

#include <Morkovka2D/Camera.hpp>
#include <Morkovka2D/Level.hpp>
#include <Morkovka2D/Renderer/Shader.hpp>

class MenuLevel : public Level {
public:
    ~MenuLevel();
    void start(World *world, Camera *camera) override;

private:
    Shader *shader;
};