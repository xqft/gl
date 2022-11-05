#pragma once
#include <GLFW/glfw3.h>

#include "graphics/camera.hpp"

struct Context 
{
    GLFWwindow* window;
    float delta_time = 0;
    Camera camera;

    void calculate_dt();
};
