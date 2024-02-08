#include "EngineCore/renderer/renderer.h"
#include "EngineCore/renderer/mesh.h"
#include <GLAD/glad.h>
#include <fmt/format.h>
#include <vector>

renderer::renderer(window_handler* window_handler)
    : _window_handler(window_handler)
{

}

renderer::~renderer()
{
}

void renderer::init()
{

}

void renderer::set_clear_color(float r, float g, float b) const { glClearColor(r, g, b, 1.0f); }
void renderer::clear_color_buffer()       const { glClear(GL_COLOR_BUFFER_BIT); }
void renderer::clear_depth_buffer()       const { glClear(GL_DEPTH_BUFFER_BIT); }
void renderer::clear_color_depth_buffer() const { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }

void renderer::render_mesh(mesh* mesh)
{
    if (!mesh)
    {
        fmt::print("Mesh cannot be renderered, it is nullptr\n");
        return;
    }

    mesh->bind();
    glDrawArrays(GL_TRIANGLES, 0, mesh->vertice_count());
}

void renderer::framebuffer_size_callback(int width, int height)
{
    fmt::print("Framebuffer changed to: width [{}]   height [{}]\n", width, height);
}


