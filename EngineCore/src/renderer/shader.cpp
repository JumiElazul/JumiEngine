#include "EngineCore/renderer/shader.h"
#include <GLAD/glad.h>
#include <fmt/format.h>
#include "core/utils.h"

shader::shader()
    : _shader_program_id()
    , _shader_linked(false)
{

}

shader::~shader()
{
    release_opengl_resources();
}

shader::shader(shader&& other) noexcept
    : _shader_program_id(other._shader_program_id)
    , _shader_linked(other._shader_linked)
{
    other._shader_program_id = 0;
    other._shader_linked = false;
}

shader& shader::operator=(shader&& other) noexcept
{
    if (this != &other)
    {
        _shader_program_id = other._shader_program_id;
        _shader_linked = other._shader_linked;

        other._shader_program_id = 0;
        other._shader_linked = false;
    }

    return *this;
}

void shader::prime_shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path)
{
    std::string vertex_shader_str = utils::stringify_file(vertex_shader_path);
    std::string fragment_shader_str = utils::stringify_file(fragment_shader_path);
    const char* vertex_shader_c_str = vertex_shader_str.c_str();
    const char* fragment_shader_c_str = fragment_shader_str.c_str();
    int success;
    char buffer[512];

    unsigned int vertex_id;
    vertex_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_id, 1, &vertex_shader_c_str, nullptr);
    glCompileShader(vertex_id);
    glGetShaderiv(vertex_id, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertex_id, 512, nullptr, buffer);
        fmt::format("{}", buffer);
        __debugbreak();
    }

    unsigned int fragment_id;
    fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_id, 1, &fragment_shader_c_str, nullptr);
    glCompileShader(fragment_id);
    glGetShaderiv(fragment_id, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragment_id, 512, nullptr, buffer);
        fmt::format("{}", buffer);
        __debugbreak();
    }

    _shader_program_id = glCreateProgram();
    glAttachShader(_shader_program_id, vertex_id);
    glAttachShader(_shader_program_id, fragment_id);
    glLinkProgram(_shader_program_id);
    glGetProgramiv(_shader_program_id, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(_shader_program_id, 512, nullptr, buffer);
        fmt::format("{}", buffer);
        __debugbreak();
    }

    glDetachShader(_shader_program_id, vertex_id);
    glDetachShader(_shader_program_id, fragment_id);
    glDeleteShader(vertex_id);
    glDeleteShader(fragment_id);

    _shader_linked = true;
}

void shader::bind() const
{
    if (!_shader_linked)
    {
        fmt::print("Cannot bind shader - shaderprogram has not been properly linked");
        return;
    }

    glUseProgram(_shader_program_id);
}

void shader::unbind() const { glUseProgram(0); }

void shader::release_opengl_resources()
{
}
