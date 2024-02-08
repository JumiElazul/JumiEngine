#include "core/callback_context.h"
#include "window/window_handler.h"
#include "input/input_handler.h"
#include "EngineCore/renderer/renderer.h"
#include <GLFW/glfw3.h>
#include <fmt/format.h>
#include <iostream>

callback_context::callback_context(window_handler& window_handler, input_handler& input_handler, renderer& renderer)
    : _window_handler(window_handler)
    , _input_handler(input_handler)
    , _renderer(renderer)
{

}

callback_context::~callback_context()
{

}

void callback_context::init()
{
    GLFWwindow* window = _window_handler.get_window();
    glfwSetWindowUserPointer(window, this);

    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_pos_callback);
    glfwSetWindowPosCallback(window, window_pos_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

window_handler& callback_context::get_window_handler() const { return _window_handler; }
input_handler& callback_context::get_input_handler() const { return _input_handler; }
renderer& callback_context::get_renderer() const { return _renderer; }

const callback_context* callback_context::get_window_user_pointer(GLFWwindow* window)
{
    const callback_context* callback_ctx = static_cast<const callback_context*>(glfwGetWindowUserPointer(window));
    if (!callback_ctx)
    {
        throw callback_exception("Callback key_callback failed to cast into WindowUserPointer");
    }
    return callback_ctx;
}

void callback_context::error_callback(int err_code, const char* description)
{
    fmt::print("[Err:{}] {}", err_code, description);
}

void callback_context::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    const callback_context* callback_ctx = get_window_user_pointer(window);
    callback_ctx->get_input_handler().key_callback(key, scancode, action, mods);
}

void callback_context::cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
    const callback_context* callback_ctx = get_window_user_pointer(window);
    callback_ctx->get_input_handler().cursor_pos_callback(xpos, ypos);
}

void callback_context::window_pos_callback(GLFWwindow* window, int xpos, int ypos)
{
    const callback_context* callback_ctx = get_window_user_pointer(window);
    callback_ctx->get_window_handler().window_pos_callback(xpos, ypos);
}

void callback_context::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    const callback_context* callback_ctx = get_window_user_pointer(window);
    callback_ctx->get_renderer().framebuffer_size_callback(width, height);
}
