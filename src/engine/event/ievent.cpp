// ievent.cpp

#include "ievent.h"

namespace StevensDev
{
namespace sgde
{

//
// CONSTRUCTOR
//

IEvent::IEvent( std::string type )
    : d_type( type )
{
}


//
// ACCESSOR
//

std::string
IEvent::type()
{
    return d_type;
}

} // end sgde namespace
} // end StevensDev namespace
