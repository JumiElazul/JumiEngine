#pragma once
#include <memory>
#include <string>
#include <GLFW/glfw3.h>

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

    const GLFWwindow* const window() const;

private:
    GLFWwindow* _window;
};

class window_handler
{
public:
    static window_handler& instance();
    void init();

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