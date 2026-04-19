#pragma once

#include <glm/glm.hpp>
#include "shader.hpp"
#include "geometry/geometry.hpp"

namespace Renderer {
    struct GlobalState {
        glm::mat4 projectionMatrix = glm::mat4(1.0);
        glm::mat4 viewMatrix = glm::mat4(1.0);
    };

    void setProjection(const glm::mat4& projection);

    void setView(const glm::mat4& view);

    void beginFrame();

    void draw(const Geometry& geometry, const Shader& shader, const glm::mat4& modelMatrix = glm::mat4(1.0), const std::function<void(const Shader&)>& setupUniforms = nullptr);
}
