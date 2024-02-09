#pragma once
#include "EngineCore/renderer/mesh.h"
#include "EngineCore/renderer/shader.h"
#include <string>
#include <unordered_map>
#include <vector>

using mesh_library = std::unordered_map<std::string, mesh>;
using shader_library = std::unordered_map<std::string, shader>;
//using texture_library = std::unordered_map<std::string, texture>;

class resource_manager
{
public:
    static resource_manager& instance();

    mesh* get_mesh(const std::string& mesh_name);
    shader* get_shader(const std::string& shader_name);

    const shader* const get_default_shader() const;

private:
    mesh_library _mesh_library;
    shader_library _shader_library;

    resource_manager();
    ~resource_manager();
    resource_manager(const resource_manager& other) = delete;
    resource_manager operator=(const resource_manager& other) = delete;
    resource_manager(resource_manager&& other) = delete;
    resource_manager operator=(resource_manager&& other) = delete;

    void init();
    void init_default_meshes();
    void init_default_shaders();
    void init_default_textures();

    static const std::string s_shader_asset_path;
    static const std::string s_basic_shader_vertex_path;
    static const std::string s_basic_shader_fragment_path;
    static const std::vector<float> s_triangle_mesh_vertices;
};
