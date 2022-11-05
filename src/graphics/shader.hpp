#pragma once

#include <vector>
#include <glad/glad.h>

namespace graphics 
{
    struct Shader
    {
        GLuint program;
        std::vector<GLuint> shaders;

        Shader();
        void add_shader(const char* path, GLenum shader_type);
        void use();
    };
}