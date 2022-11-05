#include <glm/gtc/matrix_transform.hpp>

#include "camera.hpp"

namespace graphics
{
    void Camera::move(glm::vec3 deltapos)
    {
        position += deltapos;
        lookat = glm::lookAt(position, target, up);
    }
}