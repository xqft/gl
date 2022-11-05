#include <optional>
#include <functional>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

#include "app.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/gtc/constants.hpp"
#include "graphics/graphics.hpp"
#include "graphics/camera.hpp"

namespace app 
{
    std::optional<Context> start() 
    {
        GLFWwindow* window = graphics::init();
        if (window == nullptr)
            return std::nullopt;

        Camera* camera = new Camera;

        Context context = { 
            .window = window, 
            .camera = camera 
        };
        return context;
    }

    void loop(Context& context, std::function<void()> proc) 
    {
        while (!glfwWindowShouldClose(context.window)) 
        {
            glClearColor(0.129f, 0.129f, 0.129f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            context.calculate_dt();
            context.camera->behaviour(context);

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