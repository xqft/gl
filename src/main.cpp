#include <iostream>
#include <optional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "application/app.hpp"
/*#include "ecs/ecs.hpp"

struct position : ecs::component<position> 
{
    float x, y, z;
};
struct velocity : ecs::component<velocity>
{
    float dx, dy, dz;
};
*/

int main() 
{
    std::cout << "started" << std::endl;
    std::optional<app::pack> opt_package = app::start();
    if (!opt_package.has_value()) {
        app::finish();
        return -1;
    }
    app::pack package = opt_package.value();
    app::loop(package, [] () {
        //std::cout << "Looping!" << std::endl;
    });

    app::finish();
}
