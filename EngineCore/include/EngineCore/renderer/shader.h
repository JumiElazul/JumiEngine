#pragma once
#include "../src/core/i_opengl_resource.h"
#include <string>
#include <glm/glm.hpp>

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
    void set_bool(const std::string& uniform_name, bool value) const;
    void set_int(const std::string& uniform_name, int value) const;
    void set_float(const std::string& uniform_name, float value) const;
    void set_vec3(const std::string& uniform_name, const glm::vec3& vec3) const;
    void set_mat4(const std::string& uniform_name, const glm::mat4& mat4) const;

private:
    unsigned int _shader_program_id;
    bool _shader_linked;

    int get_uniform_location(const std::string& uniform_name) const;
    virtual void release_opengl_resources() override;
};
