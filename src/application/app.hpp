#pragma once

#include <optional>
#include <functional>
#include <GLFW/glfw3.h>

namespace app 
{
    /// A 'package' that contains the application's essential objects
    struct Context 
    {
        GLFWwindow* window;
    };

    std::optional<Context> start();
    void loop(Context& context , std::function<void()>);
    void finish();
}