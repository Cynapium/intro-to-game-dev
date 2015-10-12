// input.h

#ifndef INCLUDED_INPUT
# define INCLUDED_INPUT

namespace StevensDev
{
namespace sgdi
{

#define INPUT_NB 109

enum InputType
{
    #define INPUT_MOUSE( code ) MOUSE_##code,
    #define INPUT_KEY( code )   KEY_##code,
    #include "input_type.def"
    #undef  INPUT_MOUSE
    #undef  INPUT_KEY
};

class Input
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


    // OPERATOR

    Input& operator=( const Input copy ) = delete;
      // Delete assignment operator


  public:

    // ACCESSORS

    static Input&                       inst();
      // Return the instance of Input


    // MEMBER FUNCTIONS

    void                                preTick();
      // Poll input state at this point and setup internal state

    bool                                isDown( InputType type );
      // Return true if the current input state is down

    bool                                isUp( InputType type );
      // Return true if the current input state is up

    bool                                wasPressed( InputType type );
      // Return true if the current input state was down and is now up
};

} // End sgdi namespace
} // End StevensDev namespace

#endif // INCLUDED_INPUT
