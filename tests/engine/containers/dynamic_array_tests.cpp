// dynamic_array_tests.cpp

#include "dynamic_array_tests.cpp"

DynamicArrayTest::DynamicArrayTest()
{
    d_values[0] = 42;
    d_values[1] = 13;
    d_values[2] = 37;
    d_size = 3;
}

void DynamicArrayTest::SetUp()
{
    d_arr1 = new StevensDev::sgdc::DynamicArray<int>(&d_alloc1);
    d_arr2 = new StevensDev::sgdc::DynamicArray<char*>(&d_alloc2);

    for ( int i = 0; i < d_size; i++ )
        d_arr1->push( d_values[i] );
}

void DynamicArrayTest::TearDown()
{
    delete d_arr1;
    delete d_arr2;
}

