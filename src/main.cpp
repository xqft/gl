#include <iostream>
#include <optional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "application/app.hpp"

int main() 
{
    #ifndef NDEBUG
    std::cout << "-- DEBUG MODE --" << std::endl;
    #endif
    std::cout << "Started." << std::endl;

    std::optional context = std::make_optional(app::start());
    if (!context->has_value())
        return -1;

    app::loop(context->value(), [] () {
        //std::cout << "Looping!" << std::endl;
    });

    app::finish();
}
