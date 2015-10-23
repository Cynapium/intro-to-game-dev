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


  public:

    // CONSTRUCTORS

    ICollider();
      // Default constructor


    // MEMBER FUNCTIONS

    virtual const RectangleBounds&  bounds() const = 0;
      //

    virtual unsigned short          flags() const = 0;
      //

    virtual void                    setFlags( unsigned short flags ) = 0;
      //

    virtual bool                    canCollide( unsigned short flags ) const = 0;
      //

    virtual bool                    doesCollide( const RectangleBounds& other ) = 0;
      //
};

} // end sgds namespace
} // end StevensDev namespace

#endif // Icollider
