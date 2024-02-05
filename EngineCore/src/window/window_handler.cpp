#include "EngineCore/window/window_handler.h"
#include <GLFW/glfw3.h>

glfw_window::glfw_window(const window_args& args)
    : _window(nullptr)
{
    if (args.fullscreen)
        glfwCreateWindow(args.width, args.height, args.title.c_str(), glfwGetPrimaryMonitor(), nullptr);
    else
        glfwCreateWindow(args.width, args.height, args.title.c_str(), nullptr, nullptr);
}

glfw_window::~glfw_window()
{
    glfwDestroyWindow(_window);
}

const GLFWwindow* const glfw_window::window() const
{
    return _window;
}

window_handler::window_handler()
    : _window(nullptr)
    , _initialized(false)
{

}

window_handler::~window_handler()
{

}

window_handler& window_handler::instance()
{
    static window_handler instance;
    return instance;
}

void window_handler::init()
{
    window_args w_args;
    _window = std::make_unique<glfw_window>(w_args);

    _initialized = true;

    double time = 0.0;
    while (time < 1.5)
    {
        time = glfwGetTime();
    }
}

