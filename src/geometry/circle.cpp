#include "geometry/circle.hpp"
#include <glad/glad.h>
#include <cmath>
#include <vector>

Circle::Circle(float radius, unsigned int segments) : radius(radius), segments(segments) {
    loadVerticesObjects();
}

void Circle::loadVerticesObjects() {
    std::vector<float> vertices;
    const float PI = 3.14159265358979323846f;
    vertices.insert(vertices.end(), {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f});

    for (int i = 0; i <= segments; i++) {
        float angle = (i * 2 * PI) / segments;
        float x = radius * std::cos(angle);
        float y = radius * std::sin(angle);
        vertices.insert(vertices.end(), {x, y, 0.0f});

        float red   = 0.5f + 0.5f * std::cos(angle);
        float green = 0.5f + 0.5f * std::sin(angle);
        float blue  = 1.0f;
        vertices.insert(vertices.end(), {red, green, blue});
    }

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

void Circle::draw() const {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, segments + 2);
}
