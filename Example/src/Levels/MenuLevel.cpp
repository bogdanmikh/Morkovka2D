#include "MenuLevel.hpp"

#include "Components/Menu.hpp"

MenuLevel::~MenuLevel() {
    delete shader;
}

void MenuLevel::start(World* world, Camera* camera) {
    world->addActor(new Menu());
}