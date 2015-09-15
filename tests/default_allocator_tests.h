// default_allocator_tests.h

#include <gtest/gtest.h>
#include "../src/engine/memory/default_allocator.h"

class DefaultAllocatorTest : public ::testing::Test
{
  public:

    StevensDev::sgdm::DefaultAllocator<int>     d_alloc;
    StevensDev::sgdm::DefaultAllocator<char*>    d_alloc_char;


    virtual void SetUp();
      // Set-up work for each tests

    virtual void TearDown();
      // Clean-up work for each tests

};

void DefaultAllocatorTest::SetUp()
{
}
void DefaultAllocatorTest::TearDown()
{
}

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
    ASSERT_TRUE( tmp[0] != 0);
    ASSERT_TRUE( tmp[1] != 0);
    ASSERT_TRUE( tmp[2] != 0);
    ASSERT_TRUE( tmp[3] != 0);
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
