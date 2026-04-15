#pragma once

#include <geometry/geometry.hpp>

class Triangle final : Geometry {
public:
    Triangle();

    void draw() override;

private:
    const float vertices[18] = {
        //   positions      // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

protected:
    void loadVerticesObjects() override;
};