#include "EngineCore/renderer/mesh.h"
#include <GLAD/glad.h>

mesh::mesh(const std::vector<float>& vertices)
    : _vao()
    , _vbo()
    , _vertice_count(3)
    , _vertice_size(sizeof(vertices[0]) * vertices.size())
{
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, _vertice_size, vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

mesh::~mesh()
{
    release_opengl_resources();
}

mesh::mesh(mesh&& other) noexcept
    : _vao(other._vao)
    , _vbo(other._vbo)
    , _vertice_count(other._vertice_count)
    , _vertice_size(other._vertice_size)
{
    other._vao = 0;
    other._vbo = 0;
    other._vertice_count = 0;
    other._vertice_size = 0;
}

mesh& mesh::operator=(mesh&& other) noexcept
{
    if (this != &other)
    {
        _vertice_count = other._vertice_count;
        _vertice_size = other._vertice_size;

        other._vertice_count = -1;
        other._vertice_size = -1;
    }

    return *this;
}

int mesh::vertice_count() const { return _vertice_count; }
int mesh::vertice_size() const { return _vertice_size; }

void mesh::bind() const { glBindVertexArray(_vao); }
void mesh::unbind() const { glBindVertexArray(0); }

void mesh::release_opengl_resources()
{
    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
}
