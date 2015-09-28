// stack_guard_tests.cpp

#include "stack_guard_tests.h"

// CONSTRUCTOR

StackGuardTest::StackGuardTest()
    : ptr_i( new int( 42 ) ),             guard_i( ptr_i ),
      ptr_s( new std::string( "Test" ) ), guard_s( ptr_s ), guard_n( nullptr )
{
}


// DESTRUCTOR

StackGuardTest::~StackGuardTest()
{
}
