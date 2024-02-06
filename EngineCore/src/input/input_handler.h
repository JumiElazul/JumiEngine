#pragma once
#include "core/i_sub_system.h"

struct cursor_pos
{
    double xpos;
    double ypos;
};

class input_handler : public i_sub_system
{
public:
    input_handler();
    ~input_handler();

    virtual void init() override;
    void poll_events() const;
    void key_callback(int key, int scancode, int action, int mods);
    void cursor_pos_callback(double xpos, double ypos);

private:
    bool _initialized;
    cursor_pos _cursor_pos;
};