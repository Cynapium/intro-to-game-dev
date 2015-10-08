// input.cpp

#include "input.h"

namespace StevensDev
{
namespace sgdi
{

//
// CONSTRUCTORS
//

Input::Input()
{

}


//
// ACCESSORS
//

Input&
Input::inst()
{
    return d_instance;
}


//
// MEMBER FUNCTIONS
//

bool
Input::isDown( InputType type )
{
    // TODO
    return true;
}

bool
Input::isUp( InputType type )
{
    // TODO
    return true;
}

bool
Input::wasPressed( InputType type )
{
    // TODO
    return true;
}

void
Input::preTick()
{
    // TODO
}


} // End sgdi namespace
} // End StevensDev namespace
