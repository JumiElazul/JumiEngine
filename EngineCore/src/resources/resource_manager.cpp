#include "EngineCore/resources/resource_manager.h"
#include <fmt/format.h>
#include <filesystem>
#include <stdexcept>
#include <string>

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
        fmt::print("Mesh with name [{}] does not exist in _mesh_library:", mesh_name);
        fmt::print("- {}", e.what());
        return nullptr;
    }
}

shader* resource_manager::get_shader(const std::string& shader_name)
{
    try
    {
        return &_shader_library.at(shader_name);
    }
    catch (const std::out_of_range& e)
    {
        fmt::print("Shader with name [{}] does not exist in _shader_library:", shader_name);
        fmt::print("- {}", e.what());
        return nullptr;
    }
}

const mesh* const resource_manager::get_default_mesh(primitive_shape mesh_type) const
{
    switch (mesh_type)
    {
        case primitive_shape::triangle:
        {
            return &_mesh_library.at("__TriangleMesh__");
        }
    }

    return &_mesh_library.at("__TriangleMesh__");
}

const shader* const resource_manager::get_default_shader(default_shader shader_type) const
{
    switch (shader_type)
    {
        case default_shader::basic_shader:
        {
            return &_shader_library.at("__BasicShader__");
        }
    }

    return &_shader_library.at("__BasicShader__");
}

void resource_manager::init()
{
    init_default_meshes();
    init_default_shaders();
    init_default_textures();
}

void resource_manager::init_default_meshes()
{
    _mesh_library.emplace("__TriangleMesh__", mesh{ s_triangle_mesh_vertices });
}

void resource_manager::init_default_shaders()
{
    shader basic_shader;
    basic_shader.prime_shader(s_basic_shader_vertex_path, s_basic_shader_fragment_path);
    _shader_library["__BasicShader__"] = std::move(basic_shader);
}

void resource_manager::init_default_textures()
{
}

const std::string resource_manager::s_shader_asset_path = std::filesystem::current_path().parent_path().string() + "\\assets\\shaders\\";
const std::string resource_manager::s_basic_shader_vertex_path = s_shader_asset_path + "basic_shader.vert";
const std::string resource_manager::s_basic_shader_fragment_path = s_shader_asset_path + "basic_shader.frag";

const std::vector<float> resource_manager::s_triangle_mesh_vertices
{
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
};
