#include "geometry/line.hpp"
#include <glad/glad.h>

Line::Line(const Point& p1, const Point& p2) : p1(p1), p2(p2) {
    loadVerticesObjects();
}

void Line::loadVerticesObjects() {
    float vertices[4] = {
        p1.x, p1.y,
        p2.x, p2.y
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Line::draw() const {
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);
}
