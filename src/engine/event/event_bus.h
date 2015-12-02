// event_bus.h

#ifndef INCLUDED_EVENT_BUS
# define INCLUDED_EVENT_BUS

#include "event_dispatcher.h"

namespace StevensDev
{
namespace sgde
{

class EventBus
{
  private:

    static EventBus                    *d_instance;
      // Static instance of EventBus

    static EventDispatcher              d_dispatcher;
      // Event dispatcher managed by the EventBus


    // CONSTRUCTORS

    EventBus();
      // Default constructor

    EventBus( const EventBus& copy ) = delete;
      // Copy constructor

    EventBus( EventBus&& move ) = delete;
      // Move constructor


  public:

    // OPERATORS

    EventBus& operator=( const EventBus& copy ) = delete;
      // Copy assignment operator

    EventBus& operator=( EventBus&& move ) = delete;
      // Move assignment operator


    // ACCESSOR

    static EventDispatcher& get();
      // Return the instance of EventDispatcher
};

} // end sgde namespace
} // end StevensDev namespace

#endif // EventBus
