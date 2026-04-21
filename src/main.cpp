#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "input.hpp"
#include "renderer.hpp"
#include "geometry/cube.hpp"
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
    // glm::mat4 projection = glm::ortho(-12.0f, 12.0f, -12.0f, 12.0f, -20.0f, 20.0f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),800.0f / 600.0f,0.1f,100.0f);
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -18.0f));
    Renderer::setProjection(projection);
    Renderer::setView(view);
    glEnable(GL_DEPTH_TEST);
    Cube cube;

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        Renderer::beginFrame();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, (float) glfwGetTime() * 0.8f, glm::vec3(0.0, 1.0, 0.0));
        model = glm::rotate(model, glm::radians(25.0f), glm::vec3(1.0f, 0.0f, 0.0f));

        Renderer::draw(cube, triangleShader, model);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
