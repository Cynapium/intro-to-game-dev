// dynamic_array_tests.h

#ifndef INCLUDED_DYNAMIC_ARRAY_TEST
# define INCLUDED_DYNAMIC_ARRAY_TEST

#include "../../../src/engine/memory/counting_allocator.h"
#include "../../../src/engine/containers/dynamic_array.h"

class DynamicArrayTest : public ::testing::Test
{
  public:

    int                                             d_values[3];
    int                                             d_size;

    StevensDev::sgdm::CountingAllocator<int>        d_alloc1;
    StevensDev::sgdm::CountingAllocator<char*>      d_alloc2;

    StevensDev::sgdc::DynamicArray<int>             *d_arr1;
    StevensDev::sgdc::DynamicArray<char*>           *d_arr2;


    // CONSTRUCTOR

    DynamicArrayTest();
      // Set-up work which cannot throw exception for each tests


    // MEMBER FUNCTIONS

    virtual void SetUp();
      // Set-up work for each tests

    virtual void TearDown();
      // Clean-up work for each tests

};

// length()

TEST_F( DynamicArrayTest, LengthZero )
{
    EXPECT_EQ( 0, d_arr2->length() );
}
TEST_F( DynamicArrayTest, Length )
{
    EXPECT_EQ( 3, d_arr1->length() );
}


// at

TEST_F( DynamicArrayTest, At )
{
    for ( int i = 0; i < d_size; i++ )
        EXPECT_EQ( d_values[i], d_arr1->at( i ) );
}


// operator[]

TEST_F( DynamicArrayTest, OperatorAtGet )
{
    for ( int i = 0; i < d_size; i++ )
        EXPECT_EQ( d_values[i], ( *d_arr1 )[i] );
}

TEST_F( DynamicArrayTest, OperatorAtSet )
{
    int i = d_size / 2;

    ( *d_arr1 )[i] = 99;

    EXPECT_EQ( d_size, d_arr1->length() );
    EXPECT_EQ( 99, ( *d_arr1 )[i] );
}


// insertAt, push and pushFront

TEST_F( DynamicArrayTest, InsertAt )
{
    int pos = 2;
    int val = 88;

    d_arr1->insertAt( pos, val );

    for ( int i = 0; i < d_size + 1; i++ )
    {
        if (i < pos)
            EXPECT_EQ( d_values[i], d_arr1->at( i ) );
        else if (i == pos)
            EXPECT_EQ( val, d_arr1->at( i ) );
        else
            EXPECT_EQ( d_values[i - 1], d_arr1->at( i ) );
    }
}

TEST_F( DynamicArrayTest, Push )
{
    d_arr1->push( 7 );

    for ( int i = 0; i < d_size; i++ )
        EXPECT_EQ( d_values[i], d_arr1->at( i ) );
    EXPECT_EQ( 7, d_arr1->at( 3 ) );
}

TEST_F( DynamicArrayTest, PushFront )
{
    d_arr1->pushFront( 90 );

    EXPECT_EQ( 90, d_arr1->at( 0 ) );
    for ( int i = 1; i < d_size + 1; i++ )
        EXPECT_EQ( d_values[i - 1], d_arr1->at( i ) );
}

// removeAt, pop and popFront

TEST_F( DynamicArrayTest, RemoveAt)
{
    int pos = 2;

    d_arr1->removeAt( pos );

    for ( int i = 0; i < d_size - 1; i++ )
    {
        if (i < pos)
            EXPECT_EQ( d_values[i], d_arr1->at( i ) );
        else
            EXPECT_EQ( d_values[i + 1], d_arr1->at( i ) );
    }
}

TEST_F( DynamicArrayTest, Pop)
{
    int val = d_arr1->pop();

    EXPECT_EQ( d_values[d_size - 1], val );
    for ( int i = 0; i < d_size - 1; i++ )
        EXPECT_EQ( d_values[i], d_arr1->at( i ) );

    val = d_arr1->pop();

    EXPECT_EQ( d_values[d_size - 2], val );
    for ( int i = 0; i < d_size - 2; i++ )
        EXPECT_EQ( d_values[i], d_arr1->at( i ) );
}

TEST_F( DynamicArrayTest, PopFront)
{
    int val = d_arr1->popFront();

    EXPECT_EQ( d_values[0], val );
    for ( int i = 0; i < d_size - 1; i++ )
        EXPECT_EQ( d_values[i + 1], d_arr1->at( i ) );

    val = d_arr1->popFront();

    EXPECT_EQ( d_values[d_size - 2], val );
    for ( int i = 0; i < d_size - 2; i++ )
        EXPECT_EQ( d_values[i + 2], d_arr1->at( i ) );
}

#endif // INCLUDED_DYNAMIC_ARRAY_TEST
