//
//  VertexArray.cpp
//  Neverland
//
//  Created by Admin on 14.07.2021.
//

#include "Morkovka2D/Renderer/Mesh.hpp"
#include "Morkovka2D/Renderer/VertexArray.hpp"

#include <glad/glad.h>

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) const {
    bind();
    vb.bind();
    const auto &elements = layout.getElements();
    long offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++) {
        const auto &element = elements[i];
        glEnableVertexAttribArray(i);
        int type;
        switch (element.type) {
            case BufferElementType::Float:
                type = GL_FLOAT;
                break;
            case BufferElementType::UnsignedInt:
                type = GL_UNSIGNED_INT;
                break;
            case BufferElementType::UnsignedByte:
                type = GL_UNSIGNED_BYTE;
                break;
            default:
                assert(false);
                break;
        }
        glVertexAttribPointer(i, element.count, type, element.normalized ? GL_TRUE : GL_FALSE, layout.getStride(), (const void *)offset);
        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::bind() const {
    glBindVertexArray(m_RendererID);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}
