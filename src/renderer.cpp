#include "renderer.hpp"
#include <glad/glad.h>

namespace Renderer {
    GlobalState state;

    void setProjection(const glm::mat4& projection) {
        state.projectionMatrix = projection;
    }

    void setView(const glm::mat4& view) {
        state.viewMatrix = view;
    }

    void beginFrame() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void draw(const Geometry& geometry, const Shader& shader, const glm::mat4& modelMatrix, const std::function<void(const Shader&)>& setupUniforms) {
        shader.use();
        shader.setMat4("projection", state.projectionMatrix);
        shader.setMat4("view", state.viewMatrix);
        shader.setMat4("model", modelMatrix);

        if (setupUniforms) {
            setupUniforms(shader);
        }
        geometry.draw();
    }
}
