#pragma once
#include "../src/core/i_sub_system.h"

class window_handler;
class mesh;

struct render_target
{
    int xpos;
    int ypos;
    int width;
    int height;
};

class renderer : public i_sub_system
{
friend class engine_core;
friend class callback_context;
public:
    renderer(window_handler* window_handler);
    ~renderer();
    renderer(const renderer& other) = delete;
    renderer& operator=(const renderer& other) = delete;
    renderer(const renderer&& other) = delete;
    renderer& operator=(const renderer&& other) = delete;

    virtual void init() override;
    void set_clear_color(float r, float g, float b) const;
    void clear_color_buffer() const;
    void clear_depth_buffer() const;
    void clear_color_depth_buffer() const;
    void render_mesh(const mesh* mesh);

private:
    window_handler* _window_handler;

    void framebuffer_size_callback(int width, int height);
};