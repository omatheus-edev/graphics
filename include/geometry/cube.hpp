#pragma once

#include "geometry/circle.hpp"

class Cube final : public Geometry {
public:
    const float vertices[48] = {
        -1.0f, -1.0f, -1.0f,     1.0f, 0.2f, 0.2f,
         1.0f, -1.0f, -1.0f,     1.0f, 0.2f, 0.2f,
         1.0f,  1.0f, -1.0f,     1.0f, 0.2f, 0.2f,
        -1.0f,  1.0f, -1.0f,     1.0f, 0.2f, 0.2f,

        -1.0f, -1.0f,  1.0f,     0.2f, 1.0f, 0.2f,
         1.0f, -1.0f,  1.0f,     0.2f, 1.0f, 0.2f,
         1.0f,  1.0f,  1.0f,     0.2f, 1.0f, 0.2f,
        -1.0f,  1.0f,  1.0f,     0.2f, 1.0f, 0.2f
    };

    const unsigned int indices[36] = {
        0, 1, 2,  2, 3, 0,
        4, 5, 6,  6, 7, 4,
        7, 3, 0,  0, 4, 7,
        1, 5, 6,  6, 2, 1,
        0, 1, 5,  5, 4, 0,
        3, 2, 6,  6, 7, 3
    };

    unsigned int EBO = 0;

    Cube();

    void draw() const override;

protected:
    void loadVerticesObjects() override;
};
