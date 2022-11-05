#include <iostream>
#include <optional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "graphics.hpp"

namespace graphics 
{
    static void glfw_callback(int error, const char* desc) 
    {
        std::cerr << "GLFW CALLBACK " << error << " : " << desc << std::endl;
    }

    static void GLAPIENTRY gl_callback(GLenum source, GLenum type, GLuint id,
                    GLenum severity, GLsizei, const GLchar* message,
                    const void*)
    {
        std::cerr << "GL CALLBACK : " << std::endl <<
            "type = " << std::hex << type << std::endl <<
            "severity =  " << severity << std::endl <<
            "message = " << message << std::endl <<
            "source = " << source << std::endl <<
            "id = " << id << std::endl <<
            (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "") << std::endl;
    }

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
    {
        glViewport(0, 0, width, height);
    }

    GLFWwindow* init()
    {
        std::cout << "Starting graphics..." << std::endl;

        glfwSetErrorCallback(glfw_callback);
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 30000);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            return nullptr;
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return nullptr;
        } 
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(gl_callback, 0);

        glViewport(0, 0, 800, 600);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        glEnable(GL_DEPTH_TEST);

        return window;
    }
    
}