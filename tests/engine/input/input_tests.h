// dynamic_array_tests.h

#ifndef INCLUDED_INPUT_TEST
# define INCLUDED_INPUT_TEST

#include <gtest/gtest.h>
#include "input/input.h"

class InputTest : public ::testing::Test
{
  public:

    StevensDev::sgdi::Input                 &d_in;


    // CONSTRUCTOR

    InputTest();
    // Set-up work which cannot throw exception for each tests

    // DESTRUCTOR
    virtual ~InputTest();


    // MEMBER FUNCTIONS

    virtual void SetUp();
    // Set-up work for each tests

    virtual void TearDown();
      // Clean-up work for each tests

};

#include <SFML/Window.hpp>

TEST_F( InputTest, IsDown )
{
    #define INPUT_MOUSE( key )                                             \
        EXPECT_EQ( sf::Mouse::isButtonPressed( sf::Mouse::key ),           \
                   d_in.isDown( StevensDev::sgdi::InputType::MOUSE_##key ) );


    #define INPUT_KEY( key )                                               \
        EXPECT_EQ( sf::Keyboard::isKeyPressed( sf::Keyboard::key ),        \
                   d_in.isDown( StevensDev::sgdi::InputType::KEY_##key ) );

    #include "input/input_type.def"

    #undef  INPUT_MOUSE
    #undef  INPUT_KEY
}


TEST_F( InputTest, IsUp )
{
    #define INPUT_MOUSE( key )                                             \
        EXPECT_EQ( !sf::Mouse::isButtonPressed( sf::Mouse::key ),          \
                   d_in.isUp( StevensDev::sgdi::InputType::MOUSE_##key ) );


    #define INPUT_KEY( key )                                               \
        EXPECT_EQ( !sf::Keyboard::isKeyPressed( sf::Keyboard::key ),       \
                   d_in.isUp( StevensDev::sgdi::InputType::KEY_##key ) );

    #include "input/input_type.def"

    #undef  INPUT_MOUSE
    #undef  INPUT_KEY
}

TEST_F( InputTest, WasPressed )
{
    #define INPUT_MOUSE( key )                                             \
        EXPECT_FALSE( d_in.wasPressed( StevensDev::sgdi::InputType::MOUSE_##key ) );

    #define INPUT_KEY( key )                                               \
        EXPECT_FALSE( d_in.wasPressed( StevensDev::sgdi::InputType::KEY_##key ) );

    #include "input/input_type.def"

    #undef  INPUT_MOUSE
    #undef  INPUT_KEY
}

#endif // INCLUDED_INPUT_TEST
