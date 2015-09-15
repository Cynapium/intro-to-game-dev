// counting_allocator_tests.h

#ifndef INCLUDED_COUNTING_ALLOCATOR_TEST
# define INCLUDED_COUNTING_ALLOCATOR_TEST

#include "../src/engine/memory/counting_allocator.h"

class CountingAllocatorTest : public ::testing::Test
{
  public:

    StevensDev::sgdm::CountingAllocator<int>      d_alloc;
    StevensDev::sgdm::CountingAllocator<char*>    d_alloc_char;

};

TEST_F( CountingAllocatorTest, Initialization )
{
    EXPECT_EQ( 0, d_alloc.getAllocationCount() );
    EXPECT_EQ( 0, d_alloc.getReleaseCount() );
    EXPECT_EQ( 0, d_alloc.getOutstandingCount() );
}

TEST_F( CountingAllocatorTest, SimpleAllocation )
{
    int*    tmp = d_alloc.get( 42 );

    EXPECT_EQ( 42, d_alloc.getAllocationCount() );
    EXPECT_EQ( 0,  d_alloc.getReleaseCount() );
    EXPECT_EQ( 42, d_alloc.getOutstandingCount() );
}

TEST_F( CountingAllocatorTest, SimpleRelease )
{
    int*    tmp = d_alloc.get( 42 );
    d_alloc.release( tmp, 42 );

    EXPECT_EQ( 42,  d_alloc.getAllocationCount() );
    EXPECT_EQ( 42, d_alloc.getReleaseCount() );
    EXPECT_EQ( 0,  d_alloc.getOutstandingCount() );
}

TEST_F( CountingAllocatorTest, MultipleInstances )
{
    int*    tmp_1 = d_alloc.get( 42 );
    char**  tmp_2 = d_alloc_char.get( 3 );

    d_alloc.release( tmp_1, 42 );

    EXPECT_EQ( 42, d_alloc.getAllocationCount() );
    EXPECT_EQ( 42, d_alloc.getReleaseCount() );
    EXPECT_EQ( 0, d_alloc.getOutstandingCount() );

    EXPECT_EQ( 3, d_alloc_char.getAllocationCount() );
    EXPECT_EQ( 0, d_alloc_char.getReleaseCount() );
    EXPECT_EQ( 3, d_alloc_char.getOutstandingCount() );
}

#endif // INCLUDED_COUNTING_ALLOCATOR_TEST
