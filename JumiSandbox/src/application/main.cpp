#include "EngineCore/core/engine_core.h"
#include <fmt/format.h>

int main()
{
    engine_core& core = engine_core::instance();
    core.init();
    core.show_window();

    double time = 0.0;
    while (time < 1.0)
    {
        time = core.get_time();
    }
}
