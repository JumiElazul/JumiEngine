#include "EngineCore/resources/resource_manager.h"
#include <fmt/format.h>
#include <stdexcept>

resource_manager::resource_manager() { init(); }
resource_manager::~resource_manager() { }

resource_manager& resource_manager::instance()
{
    static resource_manager instance;
    return instance;
}

mesh* resource_manager::get_mesh(const std::string& mesh_name)
{
    try
    {
        return &_mesh_library.at(mesh_name);
    }
    catch (const std::out_of_range& e)
    {
        fmt::print("Mesh with name [{}] does not exist in _mesh_library", mesh_name);
        return nullptr;
    }
}

void resource_manager::init()
{
    init_default_meshes();
    init_default_shaders();
    init_default_textures();
}

void resource_manager::init_default_meshes()
{
    _mesh_library.emplace("TriangleMesh", mesh{ s_triangle_mesh_vertices });
}

void resource_manager::init_default_shaders()
{
}

void resource_manager::init_default_textures()
{
}

const std::vector<float> resource_manager::s_triangle_mesh_vertices
{
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
};
