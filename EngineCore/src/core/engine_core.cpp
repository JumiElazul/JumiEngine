#include "EngineCore/core/engine_core.h"
#include "EngineCore/window/window_handler.h"
#include <memory>
#include <GLFW/glfw3.h>
#include <fmt/format.h>

engine_core::engine_core() 
    : _window_handler(std::make_unique<window_handler>())
    , _initialized(false) 
{ }

engine_core& engine_core::instance()
{
    static engine_core instance;
    return instance;
}

void engine_core::init()
{
    initialize_glfw();
    _window_handler->init();

    _initialized = true;
}

void engine_core::show_window()
{
    _window_handler->show_window();
}

double engine_core::get_time() const { return glfwGetTime(); }

void engine_core::initialize_glfw()
{
    if (!glfwInit())
    {
        fmt::print("Failed to initialize glfw");
    }
}
