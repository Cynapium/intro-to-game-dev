// stack_guard_tests.h

#ifndef INCLUDED_STACK_GUARD_TEST
# define INCLUDED_STACK_GUARD_TEST

#include <gtest/gtest.h>
#include "memory/stack_guard.h"

class StackGuardTest : public ::testing::Test
{
  public:

    //StevensDev::sgdm::StackGuard<std::string*> d_guard_1;

    int*                                        ptr_i;
    StevensDev::sgdm::StackGuard<int>           guard_i;

    std::string*                                ptr_s;
    StevensDev::sgdm::StackGuard<std::string>   guard_s;

    StevensDev::sgdm::StackGuard<bool>          guard_n;

    // CONSTRUCTOR

    StackGuardTest();


    // DESTRUCTOR

    ~StackGuardTest();
};

TEST_F( StackGuardTest, OperatorPtrAccess )
{
    ASSERT_EQ( 4, guard_s->length() );
}

TEST_F( StackGuardTest, OperatorNot )
{
    ASSERT_FALSE( !guard_i );
    ASSERT_FALSE( !guard_s );
    ASSERT_TRUE( !guard_n );
}

TEST_F( StackGuardTest, OperatorEquality )
{
    ASSERT_TRUE( guard_i == true );
    ASSERT_TRUE( guard_s == true );
    ASSERT_TRUE( guard_n == false );

    ASSERT_FALSE( guard_i == false );
    ASSERT_FALSE( guard_s == false );
    ASSERT_FALSE( guard_n == true );
}

TEST_F( StackGuardTest, OperatorInquality )
{
    ASSERT_FALSE( guard_i != true );
    ASSERT_FALSE( guard_s != true );
    ASSERT_FALSE( guard_n != false );

    ASSERT_TRUE( guard_i != false );
    ASSERT_TRUE( guard_s != false );
    ASSERT_TRUE( guard_n != true );
}


#endif // INCLUDED_STACK_GUARD_TEST
