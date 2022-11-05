#include <glm/gtc/matrix_transform.hpp>

#include "camera.hpp"
#include "glm/ext/matrix_transform.hpp"

glm::vec3 Camera::position = glm::zero<glm::vec3>();
glm::vec3 Camera::target = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 Camera::up = glm::vec3(0.0f, 1.0f, 0.0f);

void (*Camera::behaviour)() = nullptr;

glm::mat4 Camera::lookat()
{
    return glm::lookAt(Camera::position, Camera::target, Camera::up);
}