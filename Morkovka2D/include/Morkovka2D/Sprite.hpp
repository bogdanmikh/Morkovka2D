#pragma once

#include <glm/glm.hpp>
#include <iostream>

#include "Morkovka2D/Renderer/Shader.hpp"
#include "Morkovka2D/Renderer/Texture.hpp"
#include "Morkovka2D/Renderer/VertexArray.hpp"
#include "Morkovka2D/Renderer/VertexBuffer.hpp"

class Sprite {
public:
    Sprite(std::string texturePath, Shader *shader);
    ~Sprite();
    void setPosition(float x, float y, float z);
    void translate(float x, float y, float z);
    void setSize(float width, float height);

    float getMaxY();
    float getMinY();
    float getMaxX();
    float getMinX();

    double distanceTo(Sprite *other);

    void draw();
    bool isCollision;

private:
    void updateModelMatrix();

    Texture texture;
    VertexBuffer *vertexBuffer;
    VertexArray *vertexArray;
    glm::vec3 position;
    glm::vec2 size;

protected:
    Shader *shader;
};