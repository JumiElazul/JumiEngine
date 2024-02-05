#include "EngineCore/core/engine_core.h"
#include <fmt/format.h>

int main()
{
    engine_core& core = engine_core::instance();
    core.init();
}
