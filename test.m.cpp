// test.m.cpp

#include <gtest/gtest.h>
#include "tests/default_allocator_tests.h"
#include "tests/counting_allocator_tests.h"
#include "tests/dynamic_array_tests.h"
#include "tests/map_tests.h"

int main( int argc, char **argv )
{
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
