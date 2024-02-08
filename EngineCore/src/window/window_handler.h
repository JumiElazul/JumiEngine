#pragma once
#include "core/i_sub_system.h"
#include <memory>
#include <string>
#include <stdexcept>
#include <GLFW/glfw3.h>

class window_creation_exception : public std::runtime_error
{
public:
    inline window_creation_exception(const char* message) : std::runtime_error(message) { }
    virtual ~window_creation_exception() = default;
};

struct window_args
{
    int width = 1920;
    int height = 1080;
    std::string title = "Default Title";
    bool fullscreen = false;
};

struct window_pos
{
    int xpos;
    int ypos;
};

class glfw_window
{
public:
    glfw_window(const window_args& args);
    ~glfw_window();
    glfw_window(const glfw_window& other) = delete;
    glfw_window operator=(const glfw_window& other) = delete;
    glfw_window(const glfw_window&& other) = delete;
    glfw_window operator=(const glfw_window&& other) = delete;

    bool window_created() const;
    void create_window();
    GLFWwindow* window();

private:
    GLFWwindow* _window;
    window_args _window_args;
    bool _window_created;

    void set_window_hints() const;
};

class window_handler : public i_sub_system
{
friend class callback_context;
public:
    static window_handler& instance();
    virtual void init() override;
    void show_window(bool show = true) const;
    GLFWwindow* get_window();
    void swap_buffers() const;

    window_handler();
    ~window_handler();
    window_handler(const window_handler& other) = delete;
    window_handler& operator=(const window_handler& other) = delete;
    window_handler(const window_handler&& other) = delete;
    window_handler& operator=(const window_handler&& other) = delete;

private:
    std::unique_ptr<glfw_window> _window;
    bool _initialized;
    window_pos _window_pos;

    void cache_defaults();
    void window_pos_callback(int xpos, int ypos);
};
