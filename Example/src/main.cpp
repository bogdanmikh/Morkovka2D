#include <Morkovka2D/Window.hpp>

int main() {
    Window window("Opengl", 1000, 800 );

    while (!window.shouldClose()) {
        if(window.isKeyPressed(Key::ESCAPE)) {
            window.setShouldClose();
        }
        window.pollEvents();
        window.swapBuffers();
    }
}