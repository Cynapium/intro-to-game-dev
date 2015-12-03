// box_collider.h

#ifndef INCLUDED_BOX_COLLIDER
# define INCLUDED_BOX_COLLIDER

#include "scene/icollider.h"

namespace StevensDev
{
namespace sgds
{

class BoxCollider : public ICollider
{
  public:

    // CONSTRUCTORS

    BoxCollider( int x, int y, int width, int height );
      // Default constructor

    BoxCollider( const BoxCollider& box );
      // Copy constructor

    BoxCollider( BoxCollider&& box );
      // Move constructor


    // OPERATORS

    BoxCollider& operator=( const BoxCollider& copy );
      // Copy assignment operator

    BoxCollider& operator=( BoxCollider&& move );
      // Move assignment operator


    // MEMBER FUNCTIONS

    bool canCollide( unsigned short flags ) const;
      // Return true if the current rectangle can collide considering the flags
      // given in parameter ; false otherwise

    bool doesCollide( const RectangleBounds& rectangle );
      // Return true if the other rectangle does collide with the bounds stored
      // inside this col lider ; false otherwise
};

} // end sgds namespace
} // end StevensDev namespace

#endif // INCLUDED_BOX_COLLIDER
