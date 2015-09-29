// map_tests.h

#include "map_tests.h"

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

