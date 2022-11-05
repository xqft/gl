#pragma once
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

struct Camera
{
    static glm::vec3 position;
    static glm::vec3 target;
    static glm::vec3 up;

    static void (*behaviour)();
    
    static glm::mat4 lookat();
};