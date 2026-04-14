#pragma once

#include <geometry/geometry.hpp>

class Triangle final : Geometry {
public: 
    const float vertices[18] = {
        //   positions      // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };
    
    void loadVerticesObjects() override;
    
    void draw() override;
};