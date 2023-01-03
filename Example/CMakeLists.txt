project("Example")

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE INCLUDE src/*.hpp)

add_executable(Example "${SOURCES}" "${INCLUDE}")

# MorkovkaCore
target_link_libraries(Example MorkovkaCore)
target_include_directories(Example PRIVATE ${MCORE_DIRECTORY}/include)

# Morkovka2D
target_link_libraries(Example Morkovka2D)
target_include_directories(Example PRIVATE ${M2D_DIRECTORY}/include)