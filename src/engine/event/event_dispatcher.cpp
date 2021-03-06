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
EventDispatcher::add( const std::string& type, IEventFunc* listener )
{
    d_listeners_new.push( listener );
}

void
EventDispatcher::remove( const std::string& type, IEventFunc* listener )
{
    d_listeners_old.push( listener );
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
    // Add new listeners
    for ( int i = 0; i < d_listeners_new.length(); i++ )
    {
        d_listeners.push( d_listeners_new[i] );
    }
    d_listeners_new.clear();

    // Remove old listeners
    for ( int i = 0; i < d_listeners_old.length(); i++ )
    {
        for ( int j = 0; j < d_listeners.length(); i++ )
        {
            if ( d_listeners_old[i] == d_listeners[j] )
                d_listeners.removeAt( j );
        }
    }
    d_listeners_new.clear();
}

} // end sgde namespace
} // end StevensDev namespace
