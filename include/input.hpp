#pragma once

#include <GLFW/glfw3.h>
#include "camera.hpp"

void processInput(GLFWwindow* window, Camera& camera);

void mouseCallback(GLFWwindow* window, double xpos, double ypos);

extern Camera* g_camera;