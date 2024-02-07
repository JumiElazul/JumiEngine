#include "window/window_handler.h"
#include <fmt/format.h>
#include <GLFW/glfw3.h>

glfw_window::glfw_window(const window_args& args)
    : _window(nullptr)
    , _window_args(args)
    , _window_created(false)
{

}

glfw_window::~glfw_window() { }

bool glfw_window::window_created() const { return _window_created; }

void glfw_window::create_window()
{
    set_window_hints();
    int width = _window_args.width;
    int height = _window_args.height;
    const std::string& title = _window_args.title;
    bool fullscreen = _window_args.fullscreen;

    if (fullscreen)
        _window = glfwCreateWindow(width, height, title.c_str(), glfwGetPrimaryMonitor(), nullptr);
    else
        _window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!_window)
    {
        throw window_creation_exception("GLFWwindow could not be created");
    }
    _window_created = true;
}

void glfw_window::set_window_hints() const
{
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
}

GLFWwindow* glfw_window::window()
{
    return _window;
}

window_handler::window_handler()
    : _window(nullptr)
    , _initialized(false)
    , _window_pos()
{
}

window_handler::~window_handler()
{

}

void window_handler::cache_defaults()
{
    glfwGetWindowPos(_window->window(), &_window_pos.xpos, &_window_pos.ypos);
}

void window_handler::window_pos_callback(int xpos, int ypos)
{
    _window_pos = window_pos{ xpos, ypos };
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
    _window->create_window();

    cache_defaults();
    _initialized = true;
}

void window_handler::show_window(bool show) const
{
    if (!_initialized)
    {
        return;
    }

    GLFWwindow* const window = _window->window();
    if (show)
        glfwShowWindow(window);
    else
        glfwHideWindow(window);
}

GLFWwindow* window_handler::get_window() { return _window->window(); }

