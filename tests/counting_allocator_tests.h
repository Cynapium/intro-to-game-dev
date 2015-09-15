// counting_allocator_tests.h

#include "../src/engine/memory/counting_allocator.h"

class CountingAllocatorTest : public ::testing::Test
{
  public:

    StevensDev::sgdm::CountingAllocator<int>      d_alloc;
    StevensDev::sgdm::CountingAllocator<char*>    d_alloc_char;

    virtual void SetUp();
      // Set-up work for each tests

    virtual void TearDown();
      // Clean-up work for each tests

};

void CountingAllocatorTest::SetUp()
{
}
void CountingAllocatorTest::TearDown()
{
}

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
