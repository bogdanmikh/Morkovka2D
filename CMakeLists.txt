cmake_minimum_required(VERSION 3.16)
project("Morkovka2D")

set(CMAKE_CXX_STANDARD 14)

add_library(Morkovka2D STATIC src/main.cpp
    src/Window/Window.hpp
    src/Window/Window.cpp
    src/Renderer/Buffer.hpp
    src/Renderer/Buffer.cpp
)

# AMSTL
add_subdirectory(MorkovkaCore)
target_link_libraries(Morkovka2D MorkovkaCore)

# GLFW
add_subdirectory(vendor/glfw)
target_link_libraries(Morkovka2D glfw)
target_include_directories(Morkovka2D PRIVATE vendor/glfw/include)

# GLAD
add_subdirectory(vendor/glad)
target_link_libraries(Morkovka2D glad)
target_include_directories(Morkovka2D PRIVATE vendor/glad/include)

# GLM
add_subdirectory(vendor/glm)
target_link_libraries(Morkovka2D glm)
target_include_directories(Morkovka2D PRIVATE vendor/glm)

# STB_IMAGE
add_subdirectory(vendor/stb_image)
target_link_libraries(Morkovka2D stb_image)
target_include_directories(Morkovka2D PRIVATE vendor/stb_image)

# imgui
add_subdirectory(vendor/imgui)
target_link_libraries(Morkovka2D imgui)
target_include_directories(Morkovka2D PRIVATE vendor/imgui)
