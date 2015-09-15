// dynamic_array_tests.h

#ifndef INCLUDED_MAPS_TEST
# define INCLUDED_MAPS_TEST

#include "../src/engine/containers/maps.h"

class MapTest : public ::testing::Test
{
  public:

    Map<int>            d_map_1;


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
    : d_map_1()
{
}

void MapTest::SetUp()
{
}

void MapTest::TearDown()
{
}

MapTest::~MapTest()
{
    delete d_arr1;
    delete d_arr2;
}


#endif // INCLUDED_MAPS_TEST
