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
    d_map["one"] = 1;
    d_map["two"] = 2;
    d_map["three"] = 3;
    d_map["four"] = 4;
    d_map["five"] = 5;
    d_map["six"] = 6;
    d_map["seven"] = 7;
    d_map["eight"] = 8;
    d_map["nine"] = 9;
    d_map["ten"] = 10;

    d_map["twelve"] = 12;
}

void MapTest::TearDown()
{
}

MapTest::~MapTest()
{
}

TEST_F( MapTest, has )
{
    EXPECT_TRUE( d_map.has( "one" ) );
}

#endif // INCLUDED_MAPS_TEST
