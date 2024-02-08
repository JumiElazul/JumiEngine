#include "EngineCore/core/engine_core.h"
#include "EngineCore/renderer/renderer.h"
#include "window/window_handler.h"
#include "input/input_handler.h"
#include "core/callback_context.h"
#include <memory>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <fmt/format.h>

engine_core::engine_core() 
    : _window_handler(std::make_unique<window_handler>())
    , _input_handler(std::make_unique<input_handler>(_window_handler.get()))
    , _renderer(std::make_unique<renderer>(_window_handler.get()))
    , _callback_context(std::make_unique<callback_context>(*_window_handler, *_input_handler, *_renderer))
    , _initialized(false) 
{ }

engine_core::~engine_core()
{
    deinit();
}

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
    _renderer->init();
    _callback_context->init();
    initialize_glad();

    _initialized = true;
}

void engine_core::show_window()
{
    _window_handler->show_window();
}

double engine_core::get_time() const { return glfwGetTime(); }

void engine_core::poll_events() { _input_handler->poll_events(); }

void engine_core::swap_buffers() const { _window_handler->swap_buffers(); }

renderer& engine_core::get_renderer() { return *_renderer; }

void engine_core::initialize_glfw()
{
    if (!glfwInit())
    {
        fmt::print("Failed to initialize glfw\n");
    }
}

void engine_core::initialize_glad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fmt::print("Glad failed to load OpenGL\n");
    }
}

void engine_core::deinit()
{
    glfwTerminate();
}
