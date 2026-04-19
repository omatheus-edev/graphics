#pragma once

#include <geometry/geometry.hpp>

class Triangle final : public Geometry {
public:
    Triangle();

    void draw() const override;

private:
    const float vertices[18] = {
        //   positions      // colors
        5.0f, -5.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        -5.0f, -5.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f
    };

protected:
    void loadVerticesObjects() override;
};