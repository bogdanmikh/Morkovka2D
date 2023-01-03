#include "Morkovka2D/LevelManager.hpp"

#include <MorkovkaCore/ArrayList.hpp>

int currentLevelIndex = 0;
mcore::ArrayList<Level*> levels;
Level* menuLevel;

void setMenuLevel(Level* level) {
    menuLevel = level;
}

Level* getMenuLevel() {
    return menuLevel;
}

void pushLevel(Level* level) {
    levels.push_back(level);
}

Level* getCurrentLevel() {
    return getLevelWithIndex(currentLevelIndex);
}

Level* getLevelWithIndex(int index) {
    currentLevelIndex = index;
    if (index == -1) {
        return menuLevel;
    }
    return levels[index];
}

void increaseLevelNumber() {
    currentLevelIndex++;
    if (currentLevelIndex == levels.size()) {
        currentLevelIndex = -1;
    }
}