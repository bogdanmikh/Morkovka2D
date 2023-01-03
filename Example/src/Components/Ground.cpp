#include "Ground.hpp"

Ground::Ground(Shader* shader)
    : Sprite("textures/Earth.png", shader) {
    isCollision = true;
}

void Ground::update(double deltaTime) {
    draw();
}