#include "EngineCore/core/app_core.h"

AppCore& AppCore::instance()
{
    static AppCore instance;
    return instance;
}

int AppCore::add(int a, int b)
{
    return a + b;
}
