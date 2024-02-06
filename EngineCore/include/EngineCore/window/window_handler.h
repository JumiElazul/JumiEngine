#pragma once
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

class glfw_window
{
public:
    glfw_window(const window_args& args);
    ~glfw_window();

    bool window_created() const;
    void create_window();
    GLFWwindow* const window() const;

private:
    GLFWwindow* _window;
    window_args _window_args;
    bool _window_created;

    void set_window_hints() const;
};

class window_handler
{
public:
    static window_handler& instance();
    void init();
    void show_window(bool show = true) const;

    window_handler();
    ~window_handler();
    window_handler(const window_handler& other) = delete;
    window_handler& operator=(const window_handler& other) = delete;
    window_handler(const window_handler&& other) = delete;
    window_handler& operator=(const window_handler&& other) = delete;

private:
    std::unique_ptr<glfw_window> _window;
    bool _initialized;
};