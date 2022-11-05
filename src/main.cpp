#include <iostream>
#include <optional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "application/app.hpp"
#include "graphics/camera.hpp"
#include "graphics/shader.hpp"

int main() 
{
    int code = 0;

    #ifndef NDEBUG
    std::cout << "-- DEBUG MODE --" << std::endl;
    #endif
    std::cout << "Started." << std::endl;

    if (auto context = app::start()) {
        float vertices[] = {
            // Vertices         // Colors
             0.5f,  0.5f, 0.0f, 0.86f, 0.81f, 0.92f,
             0.5f, -0.5f, 0.0f, 0.65f, 0.38f, 0.93f,
            -0.5f,  0.5f, 0.0f, 0.65f, 0.38f, 0.93f,

             0.5f, -0.5f, 0.0f, 0.65f, 0.38f, 0.93f,
            -0.5f, -0.5f, 0.0f, 0.12f, 0.14f, 0.15f,
            -0.5f,  0.5f, 0.0f, 0.65f, 0.38f, 0.93f
        }; 

        using namespace graphics;

        GLuint VBO, VAO;
        glGenBuffers(1, &VBO);
        glGenVertexArrays(1, &VAO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);

        Shader program;
        program.add_shader("../src/graphics/shaders/vertex.glsl",  GL_VERTEX_SHADER);
        program.add_shader("../src/graphics/shaders/frag.glsl",  GL_FRAGMENT_SHADER);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0); 
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1); 
        
        app::loop(context.value(), [&] () {
            program.use();
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 6);
        });

    } else { code = -1; }

    app::finish();
    return code;
}
