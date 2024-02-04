#include "EngineCore/core/app_core.h"
#include <GLFW/glfw3.h>
#include <fmt/format.h>

AppCore::AppCore() 
    : _window(nullptr)
    , _initialized(false) 
{ }

AppCore& AppCore::instance()
{
    static AppCore instance;
    return instance;
}

void AppCore::init()
{
    if (!glfwInit())
    {
        fmt::print("Failed to initialize");
    }

    _window = glfwCreateWindow(1920, 1080, "Test Window", nullptr, nullptr);
    glfwShowWindow(_window);

    if (!_window)
    {
        glfwTerminate();
    }

    glfwMakeContextCurrent(_window);

    double time = 0.0;

    while (time < 2.0)
    {
        time = glfwGetTime();
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    _initialized = true;
}
