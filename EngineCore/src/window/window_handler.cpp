#include "EngineCore/window/window_handler.h"

window_handler::window_handler()
{

}

window_handler::~window_handler()
{

}

window_handler& window_handler::instance()
{
    static window_handler instance;
    return instance;
}
