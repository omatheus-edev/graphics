#pragma once
#include <glad/glad.h>

class Triangle final {
public:
    const float vertices[18] = {
        //   positions      // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    unsigned int VAO = 0;

    void loadVerticesObjects();
};
