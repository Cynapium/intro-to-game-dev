// test.m.cpp

#include <gtest/gtest.h>
#include "tests/engine/containers/dynamic_array_tests.h"
#include "tests/engine/containers/map_tests.h"
#include "tests/engine/memory/default_allocator_tests.h"
#include "tests/engine/memory/counting_allocator_tests.h"

//#include "tests/engine/data/json_parser.h"

int main( int argc, char **argv )
{
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
