#pragma once
#include "core/i_sub_system.h"

class window_handler;

struct cursor_pos
{
    double xpos;
    double ypos;
};

class input_handler : public i_sub_system
{
friend class callback_context;
public:
    input_handler(window_handler* window_handler);
    ~input_handler();

    virtual void init() override;
    void poll_events() const;
    void key_callback(int key, int scancode, int action, int mods);
    void cursor_pos_callback(double xpos, double ypos);
    const cursor_pos& get_cursor_pos() const;

private:
    bool _initialized;
    cursor_pos _cursor_pos;
    window_handler* _window_handler;

    void cache_defaults();
};