#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "EngineCore/renderer/mesh.h"
#include "EngineCore/renderer/shader.h"

using mesh_library = std::unordered_map<std::string, mesh>;
using shader_library = std::unordered_map<std::string, mesh>;
using texture_library = std::unordered_map<std::string, mesh>;

class resource_manager
{
public:
    static resource_manager& instance();

    mesh* get_mesh(const std::string& mesh_name);
    shader* get_shader(const std::string& shader_name);

private:
    mesh_library _mesh_library;
    shader_library _shader_library;
    texture_library _texture_library;

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

    static const std::vector<float> s_triangle_mesh_vertices;
};
