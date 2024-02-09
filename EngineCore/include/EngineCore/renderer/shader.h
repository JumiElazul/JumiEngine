#pragma once
#include "../src/core/i_opengl_resource.h"
#include <string>

class shader : public i_opengl_resource
{
public:
    shader();
    ~shader();
    shader(const shader& other) = delete;
    shader& operator=(const shader& other) = delete;
    shader(shader&& other) noexcept;
    shader& operator=(shader&& other) noexcept;

    void prime_shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path);
    void bind() const;
    void unbind() const;

private:
    unsigned int _shader_program_id;
    bool _shader_linked;

    virtual void release_opengl_resources() override;
};
