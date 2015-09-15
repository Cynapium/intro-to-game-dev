// default_allocator_tests.h

#ifndef INCLUDE_DEFAULT_ALLOCATOR
# define INCLUDE_DEFAULT_ALLOCATOR

#include <gtest/gtest.h>
#include "../src/engine/memory/default_allocator.h"

class DefaultAllocatorTest : public ::testing::Test
{
  public:

    StevensDev::sgdm::DefaultAllocator<int>      d_alloc;
};

TEST_F( DefaultAllocatorTest, SimpleAllocation )
{
    int*   tmp = d_alloc.get( 1 );

    ASSERT_TRUE( tmp != 0 );
    ASSERT_TRUE( tmp[0] != 0 );
}

TEST_F( DefaultAllocatorTest, MultipleAllocation )
{
    int*   tmp = d_alloc.get( 4 );

    ASSERT_TRUE( tmp != 0 );
    ASSERT_TRUE( tmp[0] != 0 );
    ASSERT_TRUE( tmp[1] != 0 );
    ASSERT_TRUE( tmp[2] != 0 );
    ASSERT_TRUE( tmp[3] != 0 );
}

TEST_F( DefaultAllocatorTest, SimpleRelease )
{
    int*   tmp = d_alloc.get( 1 );
    d_alloc.release( tmp, 1 );

    ASSERT_TRUE( tmp == 0 );
}

TEST_F( DefaultAllocatorTest, BiggerRelease )
{
    int*   tmp = d_alloc.get( 42 );
    d_alloc.release( tmp, 42 );

    ASSERT_TRUE( tmp == 0 );
}

#endif // INCLUDE_DEFAULT_ALLOCATOR
