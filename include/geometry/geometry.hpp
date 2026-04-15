#pragma once

#include <glad/glad.h>

class Geometry {
public:
    virtual ~Geometry() = default;

    unsigned int VBO = 0;

    unsigned int VAO = 0;

    virtual void loadVerticesObjects() = 0;

    virtual void draw() = 0;
};
