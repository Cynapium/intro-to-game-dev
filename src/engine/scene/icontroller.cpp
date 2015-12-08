// icontroller.cpp

#include "icontroller.h"

namespace StevensDev
{
namespace sgds
{

//
// CONSTRUCTORS
//

IController::IController( IActor *actor )
    : d_actor( actor )
{
}

IController::IController( const IController& controller )
    : d_actor( controller.d_actor )
{
}

IController::IController( IController&& controller )
    : d_actor( controller.d_actor )
{
    controller.d_actor = nullptr;
}

//
// DESTRUCTOR
//

IController::~IController()
{
}

//
// OPERATORS
//

IController&
IController::operator=( const IController& controller )
{
    d_actor = controller.d_actor;
}

IController&
IController::operator=( IController&& controller )
{
    d_actor = controller.d_actor;
    controller.d_actor = nullptr;
}


//
// ACCESSOR
//

IActor*
IController::actor()
{
    return d_actor;
}



} // end sgds namespace
} // end StevensDev namespace
