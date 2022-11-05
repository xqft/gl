#include <optional>
#include <GLFW/glfw3.h>

namespace app {
    /// A 'package' with the application's essential objects
    struct pack {
        GLFWwindow* window;
    };

    std::optional<pack> start();
    void loop(pack package);
    void finish();
}