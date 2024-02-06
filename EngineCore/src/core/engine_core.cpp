#include "EngineCore/core/engine_core.h"
#include "window/window_handler.h"
#include "input/input_handler.h"
#include "core/callback_context.h"
#include <memory>
#include <GLFW/glfw3.h>
#include <fmt/format.h>

engine_core::engine_core() 
    : _window_handler(std::make_unique<window_handler>())
    , _input_handler(std::make_unique<input_handler>())
    , _callback_context(std::make_unique<callback_context>(*_window_handler, *_input_handler))
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
    _input_handler->init();
    _callback_context->init();

    _initialized = true;
}

void engine_core::show_window()
{
    _window_handler->show_window();
}

double engine_core::get_time() const { return glfwGetTime(); }

void engine_core::poll_events() { _input_handler->poll_events(); }

void engine_core::initialize_glfw()
{
    if (!glfwInit())
    {
        fmt::print("Failed to initialize glfw");
    }
}
