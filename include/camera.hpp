#pragma once
#include <glm/fwd.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

class Camera final {
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    float yaw = -90.0f;
    float pitch = 0.0f;

    void recalculateView();

    void recalculateFront();

public:
    glm::mat4 view;

    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f));

    ~Camera() = default;

    void move(const glm::vec3& vec);

    void rotate(float deltaYaw, float deltaPitch);

    glm::vec3 getPosition() const {
        return position;
    }

    glm::vec3 getFront() const {
        return front;
    }

    glm::vec3 getUp() const {
        return up;
    }
};
