// default_allocator_tests.h

#ifndef INCLUDED_DEFAULT_ALLOCATOR_TEST
# define INCLUDED_DEFAULT_ALLOCATOR_TEST

#include <gtest/gtest.h>
#include "memory/default_allocator.h"

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

#endif // INCLUDED_DEFAULT_ALLOCATOR_TEST
