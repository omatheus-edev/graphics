#include "geometry/curve.hpp"

#include <complex>
#include <glad/glad.h>

Curve::Curve(float xmin, float xmax, float step) : xMin(xmin), xMax(xmax), step(step) {
    mathFunction = [](float x) -> float {
        return std::sin(x);
    };
    loadVerticesObjects();
}

void Curve::setRange(float xmin, float xmax, float step) {
    xMin = xmin;
    xMax = xmax;
    this->step = step;
    loadVerticesObjects();
}

void Curve::setFunction(std::function<float(float)> func) {
    if (func) {
        mathFunction = func;
        loadVerticesObjects();
    }
}

void Curve::loadVerticesObjects() {
    vertices.clear();

    for (float x = xMin; x <= xMax + (step * 0.5f); x += step) {
        float y = mathFunction(x);
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0.0f);
    }

    if (VAO == 0) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
    }

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Curve::draw() {
    if (VAO == 0 || vertices.empty()) return;
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(vertices.size() / 3));
    glBindVertexArray(0);
}
