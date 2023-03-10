#pragma once

#include "Morkovka2D/Level.hpp"
#include "Morkovka2D/Window.hpp"
#include "Morkovka2D/World.hpp"

class Application {
public:
    Application();
    ~Application();
    void loop();

    World world;
    Window *window;
    int fps;
    static Application *getInstance();
    void close();
    void loadLevel(Level *level);

private:
    static Application *s_instance;
    Camera *camera;
    Level *currentLevel;
    int maximumFps = 60;
    uint64_t deltaTimeMillis = 0;
    int thisSecondFramesCount = 0;
    uint64_t timeMillis;
    uint64_t oneSecondTimeCount = 0;
};