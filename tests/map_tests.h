// dynamic_array_tests.h

#ifndef INCLUDED_MAPS_TEST
# define INCLUDED_MAPS_TEST

#include "../src/engine/containers/map.h"

class MapTest : public ::testing::Test
{
  public:

      StevensDev::sgdc::Map<int> d_map;


    // CONSTRUCTOR

    MapTest();
      // Set-up work which cannot throw exception for each tests

    // DESTRUCTOR
    virtual ~MapTest();


    // MEMBER FUNCTIONS

    virtual void SetUp();
      // Set-up work for each tests

    virtual void TearDown();
      // Clean-up work for each tests

};

MapTest::MapTest()
    : d_map()
{
}

void MapTest::SetUp()
{
    d_map["twenty"] = 20;
    d_map["sixteen"] = 16;
    d_map["three"] = 3;
    d_map["one"] = 1;
    d_map["six"] = 6;
    d_map["fourteen"] = 14;
    d_map["two"] = 2;
    d_map["five"] = 5;
    d_map["ten"] = 10;
    d_map["fifteen"] = 15;
    d_map["twelve"] = 12;
}

void MapTest::TearDown()
{
}

MapTest::~MapTest()
{
}

TEST_F( MapTest, Has )
{
    EXPECT_TRUE( d_map.has( "one" ) );
    EXPECT_TRUE( d_map.has( "two" ) );
    EXPECT_TRUE( d_map.has( "three" ) );
    EXPECT_FALSE( d_map.has( "four" ) );
    EXPECT_TRUE( d_map.has( "five" ) );
    EXPECT_TRUE( d_map.has( "six" ) );
    EXPECT_FALSE( d_map.has( "seven" ) );
    EXPECT_FALSE( d_map.has( "eight" ) );
    EXPECT_FALSE( d_map.has( "nine" ) );
    EXPECT_TRUE( d_map.has( "ten" ) );
    EXPECT_FALSE( d_map.has( "eleven" ) );
    EXPECT_TRUE( d_map.has( "twelve" ) );
    EXPECT_FALSE( d_map.has( "thirteen" ) );
    EXPECT_TRUE( d_map.has( "fourteen" ) );     // Fourteen but not four
    EXPECT_TRUE( d_map.has( "fifteen" ) );      // Five and fifteen
    EXPECT_TRUE( d_map.has( "sixteen" ) );      // Six and sixteen exists
    EXPECT_FALSE( d_map.has( "seventeen" ) );   // Not seventeel but seven
    EXPECT_FALSE( d_map.has( "eighteen" ) );
    EXPECT_FALSE( d_map.has( "nineteen" ) );
    EXPECT_TRUE( d_map.has( "twenty" ) );
}

TEST_F( MapTest, GetKeys )
{
    StevensDev::sgdc::DynamicArray<std::string> keys = d_map.keys();

    EXPECT_EQ( "twenty", keys[0] );
    EXPECT_EQ( "sixteen", keys[1] );
    EXPECT_EQ( "three", keys[2] );
    EXPECT_EQ( "one", keys[3] );
    EXPECT_EQ( "six", keys[4] );
    EXPECT_EQ( "fourteen", keys[5] );
    EXPECT_EQ( "two", keys[6] );
    EXPECT_EQ( "five", keys[7] );
    EXPECT_EQ( "ten", keys[8] );
    EXPECT_EQ( "fifteen", keys[9] );
    EXPECT_EQ( "twelve", keys[10] );
}

TEST_F( MapTest, GetValues )
{
    StevensDev::sgdc::DynamicArray<int> values = d_map.values();

    EXPECT_EQ( 20, values[0] );
    EXPECT_EQ( 16, values[1] );
    EXPECT_EQ( 3, values[2] );
    EXPECT_EQ( 1, values[3] );
    EXPECT_EQ( 6, values[4] );
    EXPECT_EQ( 14, values[5] );
    EXPECT_EQ( 2, values[6] );
    EXPECT_EQ( 5, values[7] );
    EXPECT_EQ( 10, values[8] );
    EXPECT_EQ( 15, values[9] );
    EXPECT_EQ( 12, values[10] );
}

TEST_F( MapTest, OperatorAt )
{
    EXPECT_EQ( 20, d_map["twenty"] );
    EXPECT_EQ( 16, d_map["sixteen"] );
    EXPECT_EQ( 3, d_map["three"] );
    EXPECT_EQ( 1, d_map["one"] );
    EXPECT_EQ( 6, d_map["six"] );
    EXPECT_EQ( 14, d_map["fourteen"] );
    EXPECT_EQ( 2, d_map["two"] );
    EXPECT_EQ( 5, d_map["five"] );
    EXPECT_EQ( 10, d_map["ten"] );
    EXPECT_EQ( 15, d_map["fifteen"] );
    EXPECT_EQ( 12, d_map["twelve"] );
}

TEST_F( MapTest, Remove )
{
    // TODO
}

#endif // INCLUDED_MAPS_TEST
