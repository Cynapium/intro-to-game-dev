// event_dispatcher.h

#ifndef INCLUDED_EVENT_DISPATCHER
# define INCLUDED_EVENT_DISPATCHER

#include <functional>
#include "containers/dynamic_array.h"
#include "event/ievent.h"
#include "scene/itickable.h"

namespace StevensDev
{
namespace sgde
{

typedef std::function<void( const IEvent& )> IEventFunc;

class EventDispatcher : public sgds::ITickable
{
  private:

    // FIXME : Ugly solution

    sgdc::DynamicArray<EventType>  d_types;
      // Store the list of types

    sgdc::DynamicArray<EventType>  d_types_new;
      // Store the list of types

    sgdc::DynamicArray<EventType>  d_types_old;
      // Store the list of types


    sgdc::DynamicArray<IEventFunc*>  d_listeners;
      // List of listeners

    sgdc::DynamicArray<IEventFunc*>  d_listeners_new;
      // List of listeners to add for next tick

    sgdc::DynamicArray<IEventFunc*>  d_listeners_old;
      // List of listeners to remove for next tick


  public:

    // CONSTRUCTORS

    EventDispatcher();
      // Default constructor

    EventDispatcher( const EventDispatcher& copy );
      // Copy constructor

    EventDispatcher( EventDispatcher&& move );
      // Move constructor


    // OPERATORS

    EventDispatcher& operator=( const EventDispatcher& copy );
      // Copy assignment operator

    EventDispatcher& operator=( EventDispatcher&& move );
      // Move assignment operator


    // MEMBER FUNCTIONS

    void add( const EventType& type, IEventFunc* listener );
      // Add a listener to the list

    void remove( const EventType& type, IEventFunc* listener );
      // Remove a listener from the list of listeners

    void dispatch( const IEvent& event );
      // Called as part of tick, synchronous

    void preTick();
      // Does nothing

    void tick( float dts );
      // Does nothing

    void postTick();
      // Add and remove listeners
};

} // end sgde namespace
} // end StevensDev namespace

#endif // EventDispatcher
