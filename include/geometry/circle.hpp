#pragma once

#include <geometry/geometry.hpp>

class Circle final : Geometry {
public: 
    Circle(float radius, unsigned int segments);

    void loadVerticesObjects() override;

    void draw() override;

private:
    float radius;
    
    unsigned int segments;
};