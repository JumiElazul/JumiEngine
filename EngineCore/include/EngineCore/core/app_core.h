#pragma once
#include <memory>

class window_handler;

class AppCore
{
public:
    static AppCore& instance();

    void init();

private:
    std::unique_ptr<window_handler> _window_handler;
    bool _initialized;

    void initialize_glfw();

    AppCore();
    ~AppCore() = default;
    AppCore(const AppCore& other) = delete;
    AppCore& operator=(const AppCore& other) = delete;
    AppCore(const AppCore&& other) = delete;
    AppCore& operator=(const AppCore&& other) = delete;
};

