// ievent.h

#ifndef INCLUDED_IEVENT
# define INCLUDED_IEVENT

#include <string>

namespace StevensDev
{
namespace sgde
{

enum EventType
{
    ATTACK,
    COLLISION,

    // Input events
    #define INPUT_MOUSE( code ) INPUT_MOUSE_##code,
    #define INPUT_KEY( code )   INPUT_KEY_##code,
    #include "input/input_type.def"
    #undef  INPUT_MOUSE
    #undef  INPUT_KEY

    // None
    NONE
};

class IEvent
{
  protected:

    EventType             d_type;
      // Infos about the event


  public:

    // CONSTRUCTORS

    IEvent();
      // Default constructor

    IEvent( EventType type );
      // Constructor with type


    // ACCESSOR

    const EventType type() const;
      // Return information about the event


    // MUTATOR

    void setType( EventType type );
      // Set a new type for this event
};

} // end sgde namespace
} // end StevensDev namespace

#endif // IEvent
