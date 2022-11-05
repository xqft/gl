#pragma once
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/constants.hpp"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include <application/context.hpp>

namespace graphics {
    struct Camera
    {
        glm::vec3 position  = glm::zero<glm::vec3>();
        glm::vec3 target    = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up        = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 lookat    = glm::lookAt(position, target, up);

        void move(glm::vec3 deltapos);
    };
}