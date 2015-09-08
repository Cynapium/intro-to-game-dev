#include <gtest/gtest.h>

/**
 * TODO
 * These tests are supposed to go into a specific file.
 * Moreover, they are not relevant, but the project has not started so there is
 * nothing to test.
 */
TEST(Dummy, First)
{
    ASSERT_EQ(1, 1);
}
TEST(Dummy, Second)
{
    ASSERT_TRUE(true);
}
TEST(Dummy, Third)
{
    ASSERT_STREQ("Hello", "Hello");
}


/**
 * TODO
 * The tests launch is supposed to be done elsewhere.
 */
int main(int argc, char **argv)
{
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
