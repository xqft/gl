#pragma once

#include <optional>
#include <GLFW/glfw3.h>

namespace grphs 
{ // graphics related functions
    std::optional<GLFWwindow*> init();
}