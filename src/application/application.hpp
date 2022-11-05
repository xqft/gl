#pragma once

#include <optional>
#include <functional>
#include <GLFW/glfw3.h>

namespace app {
    /// A 'package' that contains the application's essential objects
    struct pack {
        GLFWwindow* window;
    };

    std::optional<pack> start();
    void loop(pack package, std::function<void()>);
    void finish();
}