//
//  VertexBufferLayout.hpp
//  Neverland
//
//  Created by Admin on 14.07.2021.
//

#pragma once

#include <glm/glm.hpp>
#include <vector>

struct Vertex {
    // position
    glm::vec3 Position;
    // texCoords
    glm::vec2 TexCoords;

    Vertex(glm::vec3 aPosition, glm::vec2 aTexCoords)
        : Position(aPosition)
        , TexCoords(aTexCoords){};
};

enum class BufferElementType { Float, UnsignedInt, UnsignedShort, UnsignedByte };

struct VertexBufferElement {
    BufferElementType type;
    uint32_t count;
    bool normalized;

    static size_t getSizeOfType(BufferElementType type) {
        switch (type) {
            case BufferElementType::Float:
                return 4;
            case BufferElementType::UnsignedInt:
                return 4;
            case BufferElementType::UnsignedShort:
                return 2;
            case BufferElementType::UnsignedByte:
                return 1;
        }
        assert(false);
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout()
        : m_Stride(0) {}
    ~VertexBufferLayout(){};

    void pushFloat(unsigned int count) {
        VertexBufferElement element = {BufferElementType::Float, count, false};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(BufferElementType::Float);
    }

    void pushUInt(unsigned int count) {
        VertexBufferElement element = {BufferElementType::UnsignedInt, count, false};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(BufferElementType::UnsignedInt);
    }

    void pushChar(unsigned int count) {
        VertexBufferElement element = {BufferElementType::UnsignedByte, count, true};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(BufferElementType::UnsignedByte);
    }

    void pushVec3F(unsigned int count) {
        VertexBufferElement element = {BufferElementType::Float, count * 3, false};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(BufferElementType::Float) * 3;
    }

    void pushVec2F(unsigned int count) {
        VertexBufferElement element = {BufferElementType::Float, count * 2, false};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(BufferElementType::Float) * 2;
    }

    void pushVertex(unsigned int count) {
        pushVec3F(1);
        pushVec2F(1);
    }

    inline const std::vector<VertexBufferElement> getElements() const {
        return m_Elements;
    }
    inline unsigned int getStride() const {
        return m_Stride;
    }
};
