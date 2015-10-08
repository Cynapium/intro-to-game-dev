// input.h

#ifndef INCLUDED_INPUT
# define INCLUDED_INPUT

#include "input_type.h"

namespace StevensDev
{
namespace sgdi
{

class Input
{
  private:

    Input                               d_instance;


    // CONSTRUCTOR

    Input();


    // MEMBER FUNCTIONS

    


  public:

    // ACCESSORS

    static Input&                       inst();
      // Return the instance of Input


    // MEMBER FUNCTIONS

    bool                                isDown( InputType type );
      // Return true if the current input state is down

    bool                                isUp( InputType type );
      // Return true if the current input state is up

    bool                                wasPressed( InputType type );
      // Return true if the current input state was down and is now up

    void                                preTick();
      // Poll input state at this point and setup internal state
};

} // End sgdi namespace
} // End StevensDev namespace

#endif // INCLUDED_INPUT
