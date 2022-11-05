#pragma once
#include <optional>
#include <functional>

#include <GLFW/glfw3.h>

#include "context.hpp"

namespace app 
{
    /// Contains the application's essential objects
    std::optional<Context> start();
    void loop(Context& context , std::function<void()>);
    void finish();
}