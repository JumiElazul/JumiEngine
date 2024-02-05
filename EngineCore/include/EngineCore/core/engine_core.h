#pragma once
#include <memory>

class window_handler;

class engine_core
{
public:
    static engine_core& instance();

    void init();

private:
    std::unique_ptr<window_handler> _window_handler;
    bool _initialized;

    void initialize_glfw();

    engine_core();
    ~engine_core() = default;
    engine_core(const engine_core& other) = delete;
    engine_core& operator=(const engine_core& other) = delete;
    engine_core(const engine_core&& other) = delete;
    engine_core& operator=(const engine_core&& other) = delete;
};

