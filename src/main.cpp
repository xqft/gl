#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void glfw_callback(int error, const char* desc) {
    std::cerr << "GLFW CALLBACK " << error << " : " << desc << std::endl;
}

void GLAPIENTRY gl_callback(GLenum source, GLenum type, GLuint id,
                 GLenum severity, GLsizei length, const GLchar* message,
                 const void* userParam)
{
    std::cerr << "GL CALLBACK : " <<
        "type = " << std::hex << type << 
        ", severity =  " << severity << 
        ", message = " << message << 
        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "");
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    std::cout << "Hello world" << std::endl;

    glfwSetErrorCallback(glfw_callback);
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    } 
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(gl_callback, 0);

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}