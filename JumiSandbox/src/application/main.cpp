#include "EngineCore/core/app_core.h"
#include <fmt/format.h>

int main()
{
    AppCore& core = AppCore::instance();
    core.init();
}
