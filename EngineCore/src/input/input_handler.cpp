#include "input/input_handler.h"
#include "window/window_handler.h"
#include <GLFW/glfw3.h>
#include <fmt/format.h>

input_handler::input_handler(window_handler* window_handler)
    : _initialized(false)
    , _cursor_pos()
    , _window_handler(window_handler)
{

}

input_handler::~input_handler()
{

}

void input_handler::init()
{
    cache_defaults();

    _initialized = true;
}

void input_handler::poll_events() const { glfwPollEvents(); }

void input_handler::key_callback(int key, int scancode, int action, int mods)
{
    fmt::print("Key [{}] - Scancode [{}] - Action [{}] - Mods [{}]\n", key, scancode, action, mods);
}

void input_handler::cursor_pos_callback(double xpos, double ypos)
{
    fmt::print("CursorPos x: [{}]  y: [{}]\n", xpos, ypos);
    _cursor_pos.xpos = xpos;
    _cursor_pos.ypos = ypos;
}

const cursor_pos& input_handler::get_cursor_pos() const { return _cursor_pos; }

void input_handler::cache_defaults()
{
    if (!_window_handler)
    {
        fmt::print("input_handler::cache_defaults failed - _window_handler is nullptr\n");
    }
    else
    {
        GLFWwindow* window = _window_handler->get_window();
        glfwGetCursorPos(window, &_cursor_pos.xpos, &_cursor_pos.ypos);
    }
}
