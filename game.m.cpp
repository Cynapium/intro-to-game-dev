#include <gtest/gtest.h>

// Tests factorial of 0.
TEST(Dummy, First)
{
    ASSERT_EQ(1, 1);
}


/**
 *
 */
int main(int argc, char **argv)
{
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
