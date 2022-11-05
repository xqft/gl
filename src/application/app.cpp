#include <optional>
#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "app.hpp"
#include "graphics/graphics.hpp"

namespace app 
{
    std::optional<pack> start() 
    {
        GLFWwindow* window = graphics::init().value_or(nullptr);
        if (window == nullptr)
            return std::nullopt;

        pack package = {window};
        return package;
    }

    void loop(pack package, std::function<void()> proc) 
    {
        while (!glfwWindowShouldClose(package.window)) 
        {
            glClearColor(0.129f, 0.129f, 0.129f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            if (proc) proc();

            glfwSwapBuffers(package.window);
            glfwPollEvents();
        }
    }

    void finish() 
    {
        glfwTerminate();
    }
}