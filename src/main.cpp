#include <MorkovkaCore/ArrayList.hpp>

#include "Window/Window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    Window window("Opengl", 1000, 800 );

    glClearColor(1.0, 1.0, 0.0, 0.0);
    mcore::vec2<uint32_t> res = window.getSize();
    while (!glfwWindowShouldClose((GLFWwindow*) window.getWindow())) {
        if (window.getSize().x != res.x || window.getSize().y != res.y) {
            res = window.getSize();
            window.resize(res);
        }
        //std::cout << glfwGetWindowSize(window.getWindow(), NULL, NULL) << '\n';
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.0, 0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers((GLFWwindow*) window.getWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
}