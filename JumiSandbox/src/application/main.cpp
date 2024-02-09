#include "EngineCore/core/engine_core.h"
#include "EngineCore/renderer/mesh.h"
#include "EngineCore/renderer/renderer.h"
#include "EngineCore/resources/resource_manager.h"
#include <fmt/format.h>

int main()
{
    engine_core& core = engine_core::instance();
    core.init();
    core.show_window();
    renderer& renderer = core.get_renderer();
    renderer.set_clear_color(1.0f, 0.0f, 0.0f);

    resource_manager& resource_manager = resource_manager::instance();
    mesh* tri_mesh = resource_manager.get_mesh("TriangleMesh");
    //shader* basic_shader = resource_manager.get_shader("BasicShader");

    double time = 0.0;
    while (time < 2.5)
    {
        core.poll_events();
        time = core.get_time();

        renderer.render_mesh(tri_mesh);

        core.swap_buffers();
        renderer.clear_color_depth_buffer();
    }
}
