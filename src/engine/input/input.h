//
// File: input.h
// Author: Barbara Crepeau
//
// Declare InputType enum, the number of input type, and Input singleton class
//

#ifndef INCLUDED_INPUT
# define INCLUDED_INPUT

#include "scene/itickable.h"

namespace StevensDev
{
namespace sgdi
{

// Number of input types
#define INPUT_NB 109

// Create an enum with all input types in input_type.def
enum InputType
{
    #define INPUT_MOUSE( code ) MOUSE_##code,
    #define INPUT_KEY( code )   KEY_##code,
    #include "input_type.def"
    #undef  INPUT_MOUSE
    #undef  INPUT_KEY
};

// Lightweight wrapper around SFML's input implementation
class Input : public sgds::ITickable
{
  private:

    static Input                       *d_instance;
      // Static instance of input

    bool                                d_state[INPUT_NB];
      // Represent the current state of all input
      // True represents DOWN, False represents UP

    bool                                d_previous[INPUT_NB];
      // Represent previous states of all input
      // True represents DOWN, False represents UP


    // CONSTRUCTOR

    Input();
      // Default constructor

    Input( const Input& copy ) = delete;
      // Delete copy constructor

    Input( Input& move ) = delete;
      // Delete move constructor


    // OPERATOR

    Input& operator=( const Input& copy ) = delete;
      // Delete copy assignment operator

    Input& operator=( Input&& move ) = delete;
      // Delete move assignment operator


  public:

    // ACCESSORS

    static Input& inst();
      // Return the instance of Input


    // MEMBER FUNCTIONS

    bool isDown( InputType type );
      // Return true if the current input state is down

    bool isUp( InputType type );
      // Return true if the current input state is up

    bool wasPressed( InputType type );
      // Return true if the current input state was down and is now up

    void preTick();
      // Poll input state at this point and setup internal state

    void tick( float dts );
      // Does nothing

    void postTick();
      // Does nothing
};

} // End sgdi namespace
} // End StevensDev namespace

#endif // INCLUDED_INPUT
