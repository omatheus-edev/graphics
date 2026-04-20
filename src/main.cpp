#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "input.hpp"
#include "renderer.hpp"
#include "geometry/triangle.hpp"
#include "geometry/circle.hpp"
#include "geometry/curve.hpp"
#include "geometry/line.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--x11") {
            glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
        }
    }
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
    glm::mat4 projection = glm::ortho(-12.0f, 12.0f, -12.0f, 12.0f, -1.0f, 1.0f);
    Triangle triangle;
    Line horizontal({-12.0f, 0}, {12.0f, 0});
    Line vertical({0, 12.0f}, {0, -12.0f});
    Renderer::setProjection(projection);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        Renderer::beginFrame();

        Renderer::draw(triangle, triangleShader);
        (glGetUniformLocation(lineShader.id, "lineColor"), 1.0f, 1.0f, 1.0f);
        glLineWidth(2.0f);
        std::function lineSetup = [](const Shader& shader) {
            shader.setVec3("lineColor", 1.0f, 1.0f, 1.0f);
        };
        Renderer::draw(horizontal, lineShader, glm::mat4(1.0), lineSetup);
        Renderer::draw(vertical, lineShader, glm::mat4(1.0), lineSetup);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
