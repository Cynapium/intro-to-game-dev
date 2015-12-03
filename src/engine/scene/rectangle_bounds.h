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

    int                   d_x;
      // Position on the x absis

    int                   d_y;
      // Position on the y absis

    int                   d_width;
      // Rectangle's width

    int                   d_height;
      // Rectangle's height


    public:

    // CONSTRUCTORS

    RectangleBounds();
      // Default constructor

    RectangleBounds( int x, int y, int width, int height );
      // Constructor with all parameters

    RectangleBounds( const RectangleBounds& rectangle );
      // Copy constructor

    RectangleBounds( RectangleBounds&& rectangle );
      // Move constructor


    // DESTRUCTOR

    virtual ~RectangleBounds();


    // ACCESSORS

    const int x() const;
      // Return the position on the x absis

    const int y() const;
      // Return the position on the y absis

    const int width() const;
      // Return the rectangle's width

    const int height() const;
      // Return the rectangle's height


    // MUTATORS

    void setX( int x );
      // Set the position on the x absis

    void setY( int y );
      // Set the position on the y absis

    void setPosition( int x, int y );
      // Set the position (x, y)

    void setWidth( int width );
      // Set the rectangle's width

    void setHeight( int height );
      // Set the rectangle's height

    void setDimensions( int width, int height );
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
