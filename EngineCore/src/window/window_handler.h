#pragma once

class window_handler
{
public:
    static window_handler& instance();

    window_handler();
    ~window_handler();
    window_handler(const window_handler& other) = delete;
    window_handler& operator=(const window_handler& other) = delete;
    window_handler(const window_handler&& other) = delete;
    window_handler& operator=(const window_handler&& other) = delete;

private:
    GLFWwindow* _window;
}