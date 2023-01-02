#pragma once

#include <iostream>
#include <MorkovkaCore/Vector2.hpp>

class Window {
private:
    mcore::vec2<uint32_t> res;
    uint32_t* window;
public:
    Window (const char* window_name, const uint16_t &resolution_x, const uint16_t &resolution_y);
    uint32_t* getWindow();
    bool checkErrors();
    mcore::vec2<uint32_t> getSize();
    void resize(mcore::vec2<uint32_t> n_res);
    void pollEvents();
    void key_isPress();
};