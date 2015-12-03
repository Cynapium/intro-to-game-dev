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

enum CollisionFlags
{
    L0,
    L1,
    L2
};

// Simple interface for defining the bounds of collission and flags appropriate
// for colliding.
class ICollider
{
  protected:

    RectangleBounds             d_bounds;
      // Bounds of the collider

    unsigned short              d_flags;
      // Bitmask of flags


  public:

    // CONSTRUCTORS

    ICollider( int x, int y, int width, int height );
      // Default constructor

    ICollider( RectangleBounds bounds, unsigned short flags );
     // Constructor with attributes


    // ACCESSOR

    const RectangleBounds& bounds() const;
      // Return a reference to the RectangleBounds stored in the Collider

    unsigned short flags() const;
      // Return the bitmask of flags


    // MUTATOR

    void setFlags( unsigned short flags );
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
