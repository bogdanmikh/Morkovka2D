//
//  VertexArray.hpp
//  Neverland
//
//  Created by Admin on 14.07.2021.
//

#pragma once

#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

class VertexArray {
private:
    unsigned int m_RendererID;

public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) const;
    void bind() const;
    void unbind() const;
};
