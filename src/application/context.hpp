#pragma once
#include <GLFW/glfw3.h>

namespace graphics { struct Camera; } // Ugly circular dependency fix :p

namespace app
{
    struct Context 
    {
        GLFWwindow* window;
        float delta_time = 0;
        graphics::Camera* camera;

        void calculate_dt();
    };
}