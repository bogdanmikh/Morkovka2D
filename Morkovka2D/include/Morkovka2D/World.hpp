#pragma once

#include "GameObject.hpp"
#include "Sprite.hpp"

#include <vector>

class World {
public:
    void update(double deltaTime);
    void addActor(GameObject* actor);
    void deleteActor(GameObject* actor);
    void deleteAll();
    std::vector<GameObject*>& getAllActors();
    std::vector<Sprite*> getAllCollisions();
private:
    std::vector<GameObject*> gameObjects;
};