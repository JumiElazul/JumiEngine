#pragma once
struct GLFWwindow;

class AppCore
{
public:
    static AppCore& instance();

    void init();

private:
    GLFWwindow* _window;
    bool _initialized;

    AppCore();
    ~AppCore() = default;
    AppCore(const AppCore& other) = delete;
    AppCore& operator=(const AppCore& other) = delete;
    AppCore(const AppCore&& other) = delete;
    AppCore& operator=(const AppCore&& other) = delete;
};

