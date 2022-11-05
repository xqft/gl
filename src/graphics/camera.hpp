#pragma once
#include "glm/gtc/constants.hpp"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

struct Camera
{
    glm::vec3 position  = glm::zero<glm::vec3>();
    glm::vec3 target    = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up        = glm::vec3(0.0f, 1.0f, 0.0f);

    void (*behaviour)() = nullptr;
    
    glm::mat4 lookat();
};