#pragma once
#include "core/i_sub_system.h"
#include <stdexcept>

class window_handler;
class input_handler;
class renderer;
struct GLFWwindow;

class callback_exception : public std::runtime_error
{
public:
    inline callback_exception(const char* message) : std::runtime_error(message) { }
    virtual ~callback_exception() = default;
};

class callback_context : public i_sub_system
{
public:
    callback_context(window_handler& window_handler, input_handler& input_handler, renderer& renderer);
    ~callback_context();

    virtual void init() override;
    window_handler& get_window_handler() const;
    input_handler& get_input_handler() const;
    renderer& get_renderer() const;

private:
    window_handler& _window_handler;
    input_handler& _input_handler;
    renderer& _renderer;

    static const callback_context* get_window_user_pointer(GLFWwindow* window);
    static void error_callback(int err_code, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
    static void window_pos_callback(GLFWwindow* window, int xpos, int ypos);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};