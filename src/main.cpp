#include <iostream>
#include <optional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "application/app.hpp"
#include "graphics/camera.hpp"

//temp
void cam_behaviour(app::Context& context)
{
    
}

int main() 
{
    int code = 0;

    #ifndef NDEBUG
    std::cout << "-- DEBUG MODE --" << std::endl;
    #endif
    std::cout << "Started." << std::endl;

    std::optional context = std::make_optional(app::start());
    if (context->has_value()) {
        context.value()->camera->behaviour = cam_behaviour;

        app::loop(context->value(), [] () {
            //std::cout << "Looping!" << std::endl;
        });
    } else { code = -1; }

    app::finish();
    return code;
}
