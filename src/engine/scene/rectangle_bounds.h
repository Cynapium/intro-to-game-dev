//
// File: rectangle_bounds.h
// Author: Barbara Crepeau
//
// Declare a RectangleBounds class
//

#ifndef INCLUDED_RECTANGLE_BOUNDS
# define INCLUDED_RECTANGLE_BOUNDS

namespace StevensDev
{
namespace sgds
{

// Represents a simple bonding box (2D)
class RectangleBounds
{
  private:

    float                   d_x;
      // Position on the x absis

    float                   d_y;
      // Position on the y absis

    float                   d_width;
      // Rectangle's width

    float                   d_height;
      // Rectangle's height


    public:

    // CONSTRUCTORS

    RectangleBounds();
      // Default constructor

    RectangleBounds( float x, float y, float width, float height );
      // Constructor with all parameters

    RectangleBounds( const RectangleBounds& rectangle );
      // Copy constructor

    RectangleBounds( RectangleBounds&& rectangle );
      // Move constructor


    // DESTRUCTOR

    virtual ~RectangleBounds();


    // ACCESSORS

    const float x() const;
      // Return the position on the x absis

    const float y() const;
      // Return the position on the y absis

    const float width() const;
      // Return the rectangle's width

    const float height() const;
      // Return the rectangle's height


    // MUTATORS

    void setX( float x );
      // Set the position on the x absis

    void setY( float y );
      // Set the position on the y absis

    void setPosition( float x, float y );
      // Set the position (x, y)

    void setWidth( float width );
      // Set the rectangle's width

    void setHeight( float height );
      // Set the rectangle's height

    void setDimensions( float width, float height );
      // Set the rectangle's dimention width and height


    // OPERATORS

    RectangleBounds& operator=( const RectangleBounds& rectangle );
      // Copy assignment operator

    RectangleBounds& operator=( RectangleBounds&& rectangle );
      // Move assignment operator


    // MEMBER FUNCTIONS

    const bool doesCollide( const RectangleBounds& candidate ) const;
      // Return true if the current and the given rectangle collide.
};

} // End sgds namespace
} // End StevensDev namespace

#endif // INCLUDED_RECTANGLE_BOUNDS
