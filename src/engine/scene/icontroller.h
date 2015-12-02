// icontroller.h

#ifndef INCLUDED_ICONTROLLER
# define INCLUDED_ICONTROLLER

#include "scene/itickable.h"
#include "scene/iactor.h"

namespace StevensDev
{
namespace sgds
{

class IController : public ITickable
{
  protected:

    IActor              *d_actor;
      // Actor controlled by the controller


  public:

    // CONSTRUCTORS

    IController( IActor *actor );
      // Default constructor

    IController( const IController& copy );
      // Copy constructor

    IController( IController&& move );
      // Move constructor

    
    // DESTRUCTOR

    virtual ~IController();
      // Destroy the controller


    // OPERATORS

    IController& operator=( const IController& copy );
      // Copy assignment operator

    IController& operator=( IController&& move );
      // Move assignment operator


    // MEMBER FUNCTIONS

    virtual void preTick() = 0;
      //

    virtual void tick( float dts ) = 0;
      //

    virtual void postTick() = 0;
      //
};

} // end sgds namespace
} // end StevensDev namespace

#endif // Icontroller
