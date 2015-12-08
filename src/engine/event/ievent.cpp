// ievent.cpp

#include "ievent.h"

namespace StevensDev
{
namespace sgde
{

//
// CONSTRUCTOR
//

IEvent::IEvent()
    : d_type( NONE )
{
}

IEvent::IEvent( EventType type )
    : d_type( type )
{
}


//
// ACCESSOR
//

const EventType
IEvent::type() const
{
    return d_type;
}


//
// MUTATOR
//

void
IEvent::setType( EventType type )
{
    d_type = type;
}

} // end sgde namespace
} // end StevensDev namespace
