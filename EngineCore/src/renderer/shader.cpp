#include "EngineCore/renderer/shader.h"
#include <GLAD/glad.h>
#include "core/utils.h"

shader::shader()
    : _id()
    , _shader_linked(false)
{

}

shader::~shader()
{
    release_opengl_resources();
}

shader::shader(shader&& other) noexcept
    : _id(other._id)
    , _shader_linked(other._shader_linked)
{
    other._id = 0;
    other._shader_linked = false;
}

shader& shader::operator=(shader&& other) noexcept
{
    if (this != &other)
    {
        _id = other._id;
        _shader_linked = other._shader_linked;

        other._id = 0;
        other._shader_linked = false;
    }

    return *this;
}

void shader::set_fragment_shader(const std::string& filepath)
{

}

void shader::set_vertex_shader(const std::string& filepath)
{

}

void shader::link_shader()
{


    _shader_linked = true;
}

void shader::bind() const
{
}

void shader::unbind() const
{
}

void shader::release_opengl_resources()
{
}
