#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <optional>

#include "application/application.hpp"


int main() {
    std::optional<app::pack> opt_package = app::start();
    if (!opt_package.has_value()) {
        app::finish();
        return -1;
    }
    app::pack package = opt_package.value();

    app::loop(package.window);

    app::finish();
    return 0;
}