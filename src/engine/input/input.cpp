// input.cpp

#include "input.h"
#include <SFML/Window.hpp>

namespace StevensDev
{
namespace sgdi
{

Input *Input::d_instance = nullptr;

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
    if ( !d_instance )
    {
        d_instance = new Input;
    }

    return *d_instance;
}


//
// MEMBER FUNCTIONS
//

bool
Input::isDown( InputType type )
{
    return d_state[type];
}

bool
Input::isUp( InputType type )
{
    return !d_state[type];
}

bool
Input::wasPressed( InputType type )
{
    return ( d_previous[type] && !d_state[type] );
}

void
Input::preTick()
{
    // Keep the previous states in the d_previous array before updating them
    for ( int i = 0; i < INPUT_NB; i++ )
    {
        d_previous[i] = d_state[i];
    }

    // Update the states
    #define INPUT_MOUSE( key )                                             \
        d_state[MOUSE_##key] = sf::Mouse::isButtonPressed( sf::Mouse::key );

    #define INPUT_KEY( key )                                               \
        d_state[KEY_##key] = sf::Keyboard::isKeyPressed( sf::Keyboard::key );

    #include "input_type.def"

    #undef  INPUT_MOUSE
    #undef  INPUT_KEY
}

void
Input::tick( float dts )
{
}

void
Input::postTick()
{
}

} // End sgdi namespace
} // End StevensDev namespace
