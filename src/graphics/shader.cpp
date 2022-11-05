#include "util/fileio.hpp"
#include "shader.hpp"

namespace graphics
{
    Shader::Shader() : program(glCreateProgram()) {}

    void Shader::add_shader(const char* path, GLenum shader_type)   // TODO: Platform dependent
    {                                                               // paths (maybe store install
        std::string source = util::read_file(path);                 // path and get absolute?)
        GLuint shader = glCreateShader(shader_type);

        const char* c_source = source.c_str();
        glShaderSource(shader, 1, &c_source, NULL);
        glCompileShader(shader);

        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char log[512];
            glGetShaderInfoLog(shader, sizeof log, NULL, log);
            // TODO: Handle err
            return;
        }
        this->shaders.push_back(shader);
        glAttachShader(this->program, shader);
    }
    void Shader::use()
    {
        glLinkProgram(this->program);
        glUseProgram(this->program);

        for (GLuint shader : this->shaders) glDeleteShader(shader);
    }
}