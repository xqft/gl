#include <GLFW/glfw3.h>

#include "context.hpp"

void Context::calculate_dt()
{
    static float old_time = 0;
    this->delta_time = glfwGetTime() - old_time;
    old_time = glfwGetTime();
}