#pragma once

#include <functional>
#include <vector>
#include <geometry/geometry.hpp>

class Curve final : Geometry {
private:
    std::pmr::vector<float> vertices;
    float xMin = -10.0f;
    float xMax = 10.0f;
    float step = 0.05f;
    std::function<float(float)> mathFunction;

public:
    Curve(float xmin = -10.0f, float xmax = 10.0f, float step = 0.05f);

    void setFunction(std::function<float(float)> func);

    void setRange(float xmin, float xmax, float step = 0.05f);

    void draw() override;

protected:
    void loadVerticesObjects() override;
};