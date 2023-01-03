#pragma once

#include "Level.hpp"

Level *getCurrentLevel();

Level *getMenuLevel();

void setMenuLevel(Level *level);

Level *getLevelWithIndex(int index);

void pushLevel(Level *level);

/// Прибавляет номер уровня на 1.
/// Если текущий уровень последний - номер становится 0
void increaseLevelNumber();