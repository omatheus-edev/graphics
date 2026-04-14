#pragma once

#include <glad/glad.h>

class Geometry {
public:
    virtual ~Geometry() = default;

    unsigned int VBO;

    unsigned int VAO;

    virtual void loadVerticesObjects() = 0;

    virtual void draw() = 0;
};
