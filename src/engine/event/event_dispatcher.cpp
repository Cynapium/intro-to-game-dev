// event_dispatcher.cpp

#include "event_dispatcher.h"

namespace StevensDev
{
namespace sgde
{

//
// CONSTRUCTORS
//

EventDispatcher::EventDispatcher()
{
}

EventDispatcher::EventDispatcher( const EventDispatcher& copy )
    : d_listeners( copy.d_listeners )
{
}

EventDispatcher::EventDispatcher( EventDispatcher&& move )
    : d_listeners( move.d_listeners )
{
    // TODO: Remove move array of listener
}


//
// OPERATORS
//

EventDispatcher&
EventDispatcher::operator=( const EventDispatcher& copy )
{
    d_listeners = copy.d_listeners;
}

EventDispatcher&
EventDispatcher::operator=( EventDispatcher&& move )
{
    d_listeners = move.d_listeners;
    // TODO: Remove move array of listener
}


//
// MEMBER FUNCTIONS
//

void
EventDispatcher::add( IEventFunc* listener )
{
    d_listeners.push( listener );
}

void
EventDispatcher::remove( IEventFunc* listener )
{
    for ( int i = 0; i < d_listeners.length(); i++ )
    {
        // FIXME: if ( d_listeners == listener )
        {
            d_listeners.removeAt( i );
            return;
        }
    }
}

void
EventDispatcher::dispatch( const IEvent& event )
{
    for ( int i = 0; i < d_listeners.length(); i++ )
    {
        ( *d_listeners[i] )( event );
    }
}

void
EventDispatcher::preTick()
{
}

void
EventDispatcher::tick( float dts )
{
}

void
EventDispatcher::postTick()
{
}

} // end sgde namespace
} // end StevensDev namespace
