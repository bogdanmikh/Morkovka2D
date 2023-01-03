#include "Buffer.hpp"

#include <glad/glad.h>

Buffer::Buffer () {
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
}