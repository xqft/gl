#pragma once
#include <GLFW/glfw3.h>

struct Camera; // Ugly circular dependency fix :p

struct Context 
{
    GLFWwindow* window;
    float delta_time = 0;
    Camera* camera;

    void calculate_dt();
};
