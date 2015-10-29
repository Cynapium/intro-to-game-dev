// event_bus.cpp

#include "event_bus.h"

namespace StevensDev
{
namespace sgde
{

EventBus *EventBus::d_instance = nullptr;

//
// CONSTRUCTOR
//

EventBus::EventBus()
    : d_dispatcher( nullptr )
{
}


//
// ACCESSOR
//

EventBus&
EventBus::inst()
{
    if ( !d_instance )
    {
        d_instance = new EventBus;
    }

    return *d_instance;
}


//
// MUTATOR
//

void
EventBus::setDispatcher( EventDispatcher *dispatcher )
{
    delete d_dispatcher;

    d_dispatcher = dispatcher;
}


//
// MEMBER FUNCTIONS
//

} // end sgde namespace
} // end StevensDev namespace
