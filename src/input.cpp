#include <input.hpp>
#include <glm/geometric.hpp>

#include "camera.hpp"

Camera* g_camera = nullptr;

static float lastX      = 400.0f;
static float lastY      = 300.0f;
static bool  firstMouse = true;
static float sensitivity = 0.1f;


void processInput(GLFWwindow* window, Camera& camera) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    float speed = 0.05f;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.move(speed * camera.getFront());
    } if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.move(-speed * camera.getFront());
    } if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.move(-glm::normalize(glm::cross(camera.getFront(), camera.getUp())) * speed);
    } if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.move(glm::normalize(glm::cross(camera.getFront(), camera.getUp())) * speed);
    }
}

void mouseCallback(GLFWwindow *window, double xpos, double ypos) {
    if (!g_camera) return;

    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float deltaX = (xpos - lastX) * sensitivity;
    float deltaY = (lastY - ypos) * sensitivity;
    lastX = xpos;
    lastY = ypos;

    g_camera->rotate(deltaX, deltaY);
}
