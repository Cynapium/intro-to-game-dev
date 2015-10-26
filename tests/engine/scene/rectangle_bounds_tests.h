// rectangle_bounds_test.h

#ifndef INCLUDED_RECTANGLE_BOUNDS_TEST
# define INCLUDED_RECTANGLE_BOUNDS_TEST

#include <gtest/gtest.h>
#include "scene/rectangle_bounds.h"

class RectangleBoundsTest : public ::testing::Test
{
  public:

    // CONSTRUCTOR

    RectangleBoundsTest();
      // Set-up work which cannot throw exception for each tests

    // DESTRUCTOR
    virtual ~RectangleBoundsTest();


    // MEMBER FUNCTIONS

    virtual void SetUp();
      // Set-up work for each tests

    virtual void TearDown();
      // Clean-up work for each tests

};

TEST_F( RectangleBoundsTest, DefaultConstructor )
{
    StevensDev::sgds::RectangleBounds         rectangle;
    float                   zero = 0;

    EXPECT_EQ( 0, rectangle.x() );
    EXPECT_EQ( 0, rectangle.y() );
    EXPECT_EQ( 0, rectangle.width() );
    EXPECT_EQ( 0, rectangle.height() );
}

TEST_F( RectangleBoundsTest, RegularConstructor )
{
    StevensDev::sgds::RectangleBounds         rectangle( 21, 10, 20, 15 );

    EXPECT_EQ( 21, rectangle.x() );
    EXPECT_EQ( 10, rectangle.y() );
    EXPECT_EQ( 20, rectangle.width() );
    EXPECT_EQ( 15, rectangle.height() );
}

TEST_F( RectangleBoundsTest, CopyConstructor )
{
    StevensDev::sgds::RectangleBounds         rectangle( 21, 10, 20, 15 );
    StevensDev::sgds::RectangleBounds         copy( rectangle );

    EXPECT_EQ( 21, copy.x() );
    EXPECT_EQ( 10, copy.y() );
    EXPECT_EQ( 20, copy.width() );
    EXPECT_EQ( 15, copy.height() );

    EXPECT_EQ( 21, rectangle.x() );
    EXPECT_EQ( 10, rectangle.y() );
    EXPECT_EQ( 20, rectangle.width() );
    EXPECT_EQ( 15, rectangle.height() );
}

TEST_F( RectangleBoundsTest, Mutators )
{
    StevensDev::sgds::RectangleBounds         rectangle;

    rectangle.setX( 10 );
    rectangle.setY( 20 );
    rectangle.setWidth( 100 );
    rectangle.setHeight( 200 );

    EXPECT_EQ( 10, rectangle.x() );
    EXPECT_EQ( 20, rectangle.y() );
    EXPECT_EQ( 100, rectangle.width() );
    EXPECT_EQ( 200, rectangle.height() );

    rectangle.setPosition( 13, 37 );
    rectangle.setDimensions( 40, 42 );

    EXPECT_EQ( 13, rectangle.x() );
    EXPECT_EQ( 37, rectangle.y() );
    EXPECT_EQ( 40, rectangle.width() );
    EXPECT_EQ( 42, rectangle.height() );
}

TEST_F( RectangleBoundsTest, Collisions )
{
    StevensDev::sgds::RectangleBounds         base( 1, 1, 4, 3 );
    StevensDev::sgds::RectangleBounds         r_far( 7, 3, 3, 2 );  // Far away from base
    StevensDev::sgds::RectangleBounds         r_adj( 5, 2, 3, 2 );  // Adjacent to base
    StevensDev::sgds::RectangleBounds         r_near( 2, 4, 2, 3 );  // Collide with base
    StevensDev::sgds::RectangleBounds         r_zero( 2, 2, 0, 0 ); // Inside but dimensions 0
    StevensDev::sgds::RectangleBounds         r_col( 0, 3, 3, 5 ); // Collide with base
    StevensDev::sgds::RectangleBounds         r_ins( 2, 2, 2, 1 );  // Inside base
    StevensDev::sgds::RectangleBounds         r_same( 1, 1, 4, 3 ); // Same

    EXPECT_FALSE( base.doesCollide( r_far ) );
    EXPECT_FALSE( base.doesCollide( r_adj ) );
    EXPECT_FALSE( base.doesCollide( r_zero ) );
    EXPECT_FALSE( base.doesCollide( r_near ) );

    EXPECT_TRUE( base.doesCollide( r_col ) );
    EXPECT_TRUE( base.doesCollide( r_ins ) );
    EXPECT_TRUE( base.doesCollide( r_same ) );
}

#endif // INCLUDED_RECTANGLE_BOUNDS_TEST
