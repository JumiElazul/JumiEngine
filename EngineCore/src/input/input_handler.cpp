#include "input/input_handler.h"
#include <GLFW/glfw3.h>
#include <fmt/format.h>

input_handler::input_handler()
    : _initialized(false)
    , _cursor_pos(0, 0)
{

}

input_handler::~input_handler()
{

}

void input_handler::init()
{


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
