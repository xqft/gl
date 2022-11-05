#include <glm/gtc/matrix_transform.hpp>

#include "camera.hpp"

namespace graphics
{
    glm::mat4 Camera::lookat()
    {
        return glm::lookAt(this->position, this->target, this->up);
    }
}