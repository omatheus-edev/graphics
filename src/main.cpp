#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "input.hpp"
#include "renderer.hpp"
#include "geometry/triangle.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--x11") {
            glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
        }
    }
    setenv("XDG_SESSION_TYPE", "x11", 1);
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
    glm::mat4 projection = glm::ortho(-12.0f, 12.0f, -12.0f, 12.0f, -1.0f, 1.0f);
    Triangle triangle;
    Renderer::setProjection(projection);
    Renderer::setView(glm::mat4(1.0f));

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        Renderer::beginFrame();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.5f, -0.5f, 0.0f));
        model = glm::rotate(model, (float) glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));
        Renderer::draw(triangle, triangleShader, model);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
