#pragma once

#include <geometry/geometry.hpp>

class Circle final : Geometry {
public: 

    void loadVerticesObjects() override;

    void draw() override;
private:
    float radius;
    
    int segment;
};