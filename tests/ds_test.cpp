#include <gtest/gtest.h>
#include <data_structures/data_structures.h>

TEST(DsTests, TestName_Henry)
{
    Person jimmy{"Jimmy", 23};
    auto expected = "Jimmy";
    auto result = jimmy.getname();
    ASSERT_EQ(*expected, *result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}