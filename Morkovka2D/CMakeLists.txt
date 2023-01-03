project("Morkovka2D")

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE INCLUDE src/*.hpp include/Morkovka2D/*.hpp)

add_library(Morkovka2D STATIC "${SOURCES}" "${INCLUDE}")

target_include_directories(Morkovka2D PRIVATE ${M2D_DIRECTORY}/include)

# MorkovkaCore
target_link_libraries(Morkovka2D MorkovkaCore)
target_include_directories(Morkovka2D PRIVATE ${MCORE_DIRECTORY}/include)

# GLFW
target_link_libraries(Morkovka2D glfw)
target_include_directories(Morkovka2D PRIVATE ${VENDOR_DIRECTORY}/glfw/include)

# GLAD
target_link_libraries(Morkovka2D glad)
target_include_directories(Morkovka2D PRIVATE ${VENDOR_DIRECTORY}/glad/include)

# GLM
target_link_libraries(Morkovka2D glm)
target_include_directories(Morkovka2D PRIVATE ${VENDOR_DIRECTORY}/glm)

# STB_IMAGE
target_link_libraries(Morkovka2D stb_image)
target_include_directories(Morkovka2D PRIVATE ${VENDOR_DIRECTORY}/stb_image)

# imgui
target_link_libraries(Morkovka2D imgui)
target_include_directories(Morkovka2D PRIVATE ${VENDOR_DIRECTORY}/imgui)
