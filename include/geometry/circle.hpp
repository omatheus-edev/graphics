#pragma once

#include <geometry/geometry.hpp>

class Circle final : public Geometry {
public: 
    Circle(float radius, unsigned int segments);

    void draw() const override;

private:
    float radius;
    
    unsigned int segments;

protected:
    void loadVerticesObjects() override;
};