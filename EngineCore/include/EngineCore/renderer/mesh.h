#pragma once
#include "../src/core/i_opengl_resource.h"
#include <vector>

class mesh : public i_opengl_resource
{
public:
    mesh(const std::vector<float>& vertices);
    ~mesh();
    mesh(const mesh& other) = delete;
    mesh& operator=(const mesh& other) = delete;
    mesh(mesh&& other) noexcept;
    mesh& operator=(mesh&& other) noexcept;

    int vertice_count() const;
    int vertice_size() const;
    void bind() const;
    void unbind() const;

private:
    unsigned int _vao;
    unsigned int _vbo;
    int _vertice_count;
    int _vertice_size;

    virtual void release_opengl_resources() override;
};