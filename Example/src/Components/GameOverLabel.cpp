#include "GameOverLabel.hpp"

#include <Morkovka2D/Application.hpp>
#include <Morkovka2D/LevelManager.hpp>

GameOverLabel::GameOverLabel(Shader *shader, Player *player)
    : Sprite("textures/GameOverLabel.png", shader)
    , labelTime(0.0) {
    setPosition(player->getMinX() - 2.5, player->getMinY() + 0.2, 0.f);
    setSize(5.0, 2.5);
}

void GameOverLabel::update(double deltaTime) {
    labelTime += deltaTime;
    std::cout << "LebelTime: " << labelTime << " deltaTime: " << deltaTime << '\n';
    if (labelTime >= 1) {
        Application::getInstance()->loadLevel(getCurrentLevel());
        return;
    }
    draw();
}