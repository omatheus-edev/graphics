#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "input.hpp"
#include "geometry/triangle.hpp"
#include "shader.hpp"
#include "geometry/circle.hpp"
#include "geometry/curve.hpp"
#include "geometry/line.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int heigh) {
    glViewport(0, 0, width, heigh);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR , 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR , 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "opengl", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader triangleShader("shaders/triangle.vs", "shaders/triangle.fs");
    Shader lineShader("shaders/line.vs", "shaders/line.fs");
    // Circle circle(0.75f, 64);
    Triangle triangle;
    Line l1({-0.5f, -0.5f}, {0.0f, 0.5f});
    Line l2({0.0f, 0.5f}, {0.5f, -0.5f});
    Line l3({0.5f, -0.5f}, {-0.5f, -0.5f});

    Curve curve(-5.0f, 5.0f, 0.02f);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT);

        // triangleShader.use();
        // triangle.draw();

        lineShader.use();
        // glUniform3f(glGetUniformLocation(lineShader.id, "lineColor"), 1.0f, 1.0f, 1.0f);

        glUniform3f(glGetUniformLocation(lineShader.id, "lineColor"),
                    1.0f, 0.8f, 0.2f);
        glLineWidth(2.0f);
        curve.draw();
        // l1.draw();
        // l2.draw();
        // l3.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
