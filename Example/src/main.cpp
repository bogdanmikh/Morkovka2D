#include <Morkovka2D/Application.hpp>
#include <Morkovka2D/LevelManager.hpp>

#include "Levels/MenuLevel.hpp"
#include "Levels/FirstLevel.hpp"
#include "Levels/SecondLevel.hpp"

int main() {
    setMenuLevel(new MenuLevel);
    Application app;
    pushLevel(new FirstLevel);
    pushLevel(new SecondLevel);
    app.loop();
}