#pragma once
#include <memory>

class window_handler;
class input_handler;
class callback_context;
class renderer;

class engine_core
{
public:
    static engine_core& instance();

    void init();
    void show_window();
    double get_time() const;
    void poll_events();
    void swap_buffers() const;
    renderer& get_renderer();

private:
    std::unique_ptr<window_handler> _window_handler;
    std::unique_ptr<input_handler> _input_handler;
    std::unique_ptr<renderer> _renderer;
    std::unique_ptr<callback_context> _callback_context;
    bool _initialized;

    void initialize_glfw();
    void initialize_glad();
    void deinit();

    engine_core();
    ~engine_core();
    engine_core(const engine_core& other) = delete;
    engine_core& operator=(const engine_core& other) = delete;
    engine_core(const engine_core&& other) = delete;
    engine_core& operator=(const engine_core&& other) = delete;
};

