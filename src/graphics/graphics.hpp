#pragma once

#include <optional>
#include <GLFW/glfw3.h>

namespace graphics 
{ // graphics related functions
    std::optional<GLFWwindow*> init();
}