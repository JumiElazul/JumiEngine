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

    void set_fragment_shader(const std::string& filepath);
    void set_vertex_shader(const std::string& filepath);
    void link_shader();
    void bind() const;
    void unbind() const;

private:
    unsigned int _id;
    bool _shader_linked;

    virtual void release_opengl_resources() override;
};
