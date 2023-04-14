#include <gtest/gtest.h>
#include <data_structures/data_structures.h>


TEST(DsTests, TestName_Henry)
{
    Person jimmy{"Jimmy", 23};
    auto expected = "Jimmy";
    auto result = jimmy.getname();
    ASSERT_EQ(*expected, *result);
}

TEST(ArrayTests, TestArray)
{
    std::array<int, 4> fib{0, 1, 2, 0};
    int fib_front = fib.front();
    int expcted = 1;
    ASSERT_EQ(fib.front(), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}