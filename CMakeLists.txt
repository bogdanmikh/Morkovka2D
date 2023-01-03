cmake_minimum_required(VERSION 3.16)
project("Morkovka2D")

set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

set(CMAKE_CXX_STANDARD 14)

set(BIN_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(M2D_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Morkovka2D)
set(MCORE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/MorkovkaCore)
set(VENDOR_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

# Vendor dependencies
add_subdirectory(${VENDOR_DIRECTORY}/glfw)
add_subdirectory(${VENDOR_DIRECTORY}/glad)
add_subdirectory(${VENDOR_DIRECTORY}/glm)
add_subdirectory(${VENDOR_DIRECTORY}/stb_image)
add_subdirectory(${VENDOR_DIRECTORY}/imgui)

# Morkovka dependencies
add_subdirectory(MorkovkaCore)
add_subdirectory(Morkovka2D)

# Game
add_subdirectory(Example)