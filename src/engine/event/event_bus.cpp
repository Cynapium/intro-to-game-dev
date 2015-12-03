// event_bus.cpp

#include "event_bus.h"

namespace StevensDev
{
namespace sgde
{

EventBus *EventBus::d_instance = nullptr;
EventDispatcher EventBus::d_dispatcher;

//
// CONSTRUCTOR
//

EventBus::EventBus()
{
}


//
// ACCESSOR
//

EventDispatcher&
EventBus::dispatcher()
{
    if ( !d_instance )
    {
        d_instance = new EventBus;
    }

    return d_dispatcher;
}


} // end sgde namespace
} // end StevensDev namespace
