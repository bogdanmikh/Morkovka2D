#include "Window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Window::Window(const char* window_name, const uint16_t &resolution_x, const uint16_t &resolution_y) {
    if (!glfwInit()) {
        std::cerr << "GLWF not init\n";
        return;
    }
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    this->window = (uint32_t*) glfwCreateWindow(resolution_x, resolution_y, window_name, NULL, NULL);
    if (!window) {
        std::cerr << "window did not open\n";
        glfwTerminate();
    }
    glfwMakeContextCurrent((GLFWwindow*) window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize OpenGL context" << std::endl;
        glfwTerminate();
    }
    this->res.x = resolution_x;
    this->res.y = resolution_y;
}

void Window::pollEvents() {
    glfwPollEvents();
}

uint32_t* Window::getWindow() {
    return window;
}

mcore::vec2<uint32_t> Window::getSize() {
    return res;
}

void Window::resize (mcore::vec2<uint32_t> n_res) {
    glfwTerminate();
    if (!glfwInit()) {
        std::cerr << "GLWF not init\n";
        return;
    }
    this->window = (uint32_t*) glfwCreateWindow(n_res.x, n_res.y, NULL, NULL, NULL);
    if (!window) {
        std::cerr << "window did not open\n";
        glfwTerminate();
    }
    glfwMakeContextCurrent((GLFWwindow*) window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize OpenGL context" << std::endl;
        glfwTerminate();
    }
    this->res.x = n_res.x;
    this->res.y = n_res.y;
}

