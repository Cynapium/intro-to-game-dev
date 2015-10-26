// icollider.h

#ifndef INCLUDED_ICOLLIDER
# define INCLUDED_ICOLLIDER

#include "rectangle_bounds.h"

namespace StevensDev
{
namespace sgds
{

class ICollider
{
  private:

    RectangleBounds             d_bounds;
      // Bounds of the collider

    unsigned short              d_flags;
      // Flags


  public:

    // CONSTRUCTORS

    ICollider();
      // Default constructor


    // ACCESSOR

    virtual const RectangleBounds& bounds() const = 0;
      // Return a reference to the RectangleBounds stored in the Collider

    virtual unsigned short      flags() const = 0;
      // Return a copy of the flags


    // MUTATOR

    virtual void                setFlags( unsigned short flags ) = 0;
      // Set the flags for this Collider


    // MEMBER FUNCTIONS

    virtual bool                canCollide( unsigned short flags ) const = 0;
      // Return true if the current rectangle can collide considering the flags
      // given in parameter ; false otherwise

    virtual bool                doesCollide( const RectangleBounds& rec ) = 0;
      // Return true if the other rectangle does collide with the bounds stored
      // inside this collider ; false otherwise
};

} // end sgds namespace
} // end StevensDev namespace

#endif // Icollider
