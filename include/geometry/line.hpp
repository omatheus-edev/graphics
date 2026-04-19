#pragma once

#include "geometry/geometry.hpp"

class Line final : public Geometry {
public:
    struct Point {
        float x;
        float y;
    };

    Point p1;

    Point p2;

    Line(const Point& p1, const Point& p2);

    void draw() const override;

protected:
    void loadVerticesObjects() override;
};