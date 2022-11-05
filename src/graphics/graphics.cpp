#include <iostream>
#include <optional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "graphics.hpp"

namespace grphs 
{
    static void glfw_callback(int error, const char* desc) 
    {
        std::cerr << "GLFW CALLBACK " << error << " : " << desc << std::endl;
    }

    static void GLAPIENTRY gl_callback(GLenum source, GLenum type, GLuint id,
                    GLenum severity, GLsizei, const GLchar* message,
                    const void*)
    {
        std::cerr << "GL CALLBACK : " <<
            "type = " << std::hex << type << 
            ", severity =  " << severity << 
            ", message = " << message << 
            ", source = " << source <<
            ", id = " << id <<
            (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "") << std::endl;
    }

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
    {
        glViewport(0, 0, width, height);
    }

    std::optional<GLFWwindow*> init() 
    {
        std::cout << "Starting graphics..." << std::endl;

        glfwSetErrorCallback(glfw_callback);
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return std::nullopt;
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return std::nullopt;
        } 
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(gl_callback, 0);

        glViewport(0, 0, 800, 600);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        return window;
    }
    
}