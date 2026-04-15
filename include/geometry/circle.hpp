#pragma once

#include <geometry/geometry.hpp>

class Circle final : Geometry {
public: 
    Circle(float radius, unsigned int segments);

    void draw() override;

private:
    float radius;
    
    unsigned int segments;

protected:
    void loadVerticesObjects() override;
};