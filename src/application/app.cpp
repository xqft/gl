#include <optional>
#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "app.hpp"
#include "graphics/graphics.hpp"

namespace app 
{
    std::optional<Context> start() 
    {
        GLFWwindow* window = graphics::init();
        if (window == nullptr)
            return std::nullopt;

        Context context = { window };
        return context;
    }

    void loop(Context context, std::function<void()> proc) 
    {
        while (!glfwWindowShouldClose(context.window)) 
        {
            glClearColor(0.129f, 0.129f, 0.129f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            if (proc) proc();

            glfwSwapBuffers(context.window);
            glfwPollEvents();
        }
    }

    void finish() 
    {
        glfwTerminate();
    }
}