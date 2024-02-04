#include "EngineCore/core/app_core.h"
#include <memory>
#include <GLFW/glfw3.h>
#include <fmt/format.h>

AppCore::AppCore() 
    : _window_handler(std::make_unique<window_handler>())
    , _initialized(false) 
{ }

AppCore& AppCore::instance()
{
    static AppCore instance;
    return instance;
}

void AppCore::init()
{
    initialize_glfw();

    _initialized = true;
}

void AppCore::initialize_glfw()
{
    if (!glfwInit())
    {
        fmt::print("Failed to initialize");
    }
}
