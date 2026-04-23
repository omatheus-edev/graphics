#include "camera.hpp"

#include <glm/ext/matrix_transform.hpp>

Camera::Camera(glm::vec3 position) : position(position), front(glm::vec3(0.0f, 0.0f, -1.0f)), up(0.0f, 1.0f, 0.0f) {
    recalculateView();
}

void Camera::recalculateView() {
    view = glm::lookAt(position, position + front, up);
}

void Camera::recalculateFront() {
    glm::vec3 dir;
    dir.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
    dir.y = glm::sin(glm::radians(pitch));
    dir.z = glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
    front = glm::normalize(dir);
}

void Camera::move(const glm::vec3& vec) {
    position += vec;
    recalculateView();
}

void Camera::rotate(float deltaYaw, float deltaPitch) {
    yaw += deltaYaw;
    pitch += deltaPitch;

    if (pitch >  89.0f) pitch =  89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    recalculateFront();
    recalculateView();
}
