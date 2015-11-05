//
// File: icollider.h
// Author: Barbara Crepeau
//
// Declare a ICollider interface to have a layer of abstraction above a
// bounding container
//

#ifndef INCLUDED_ICOLLIDER
# define INCLUDED_ICOLLIDER

#include "rectangle_bounds.h"

namespace StevensDev
{
namespace sgds
{

// Simple interface for defining the bounds of collission and flags appropriate
// for colliding.
class ICollider
{
  private:

    RectangleBounds             d_bounds;
      // Bounds of the collider

    unsigned short              d_flags;
      // Bitmask of flags


  public:

    // CONSTRUCTORS

    ICollider();
      // Default constructor


    // ACCESSOR

    virtual const RectangleBounds& bounds() const = 0;
      // Return a reference to the RectangleBounds stored in the Collider

    virtual unsigned short flags() const = 0;
      // Return the bitmask of flags


    // MUTATOR

    virtual void setFlags( unsigned short flags ) = 0;
      // Set the flags for this Collider


    // MEMBER FUNCTIONS

    virtual bool canCollide( unsigned short flags ) const = 0;
      // Return true if the current rectangle can collide considering the flags
      // given in parameter ; false otherwise

    virtual bool doesCollide( const RectangleBounds& rectangle ) = 0;
      // Return true if the other rectangle does collide with the bounds stored
      // inside this col lider ; false otherwise
};

} // end sgds namespace
} // end StevensDev namespace

#endif // INCLUDED_ICOLLIDER
