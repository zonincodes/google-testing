#include <gtest/gtest.h>
#include <data_structures/data_structures.h>
#include <map>
#include <string>

#include <bitset>
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

TEST(BitsetTests, Bitset_support_interger_initialization){
    std::bitset<4> bs(0b0101);
    EXPECT_TRUE(bs[0]);
    EXPECT_FALSE(bs[1]);
    EXPECT_TRUE(bs[2]);
    EXPECT_FALSE(bs[3]);
}

TEST(MapTest, Supports)
{
    // Test default construction
    {
        std::map<const char *, int> emp;
        EXPECT_TRUE(emp.empty());
    }

    // Test braced initialization
    {
        const char *colour_of_magic = "Colour of Magic";
        const char *the_light_fantastic = "The Light Fantastic";
        const char *equal_rites = "Equal Rites";
        const char *mort = "Mort";

        std::map<const char *, int> pub_year{
            {colour_of_magic, 1983},
            {the_light_fantastic, 1986},
            {equal_rites, 1987},
            {mort, 1987}};

        EXPECT_EQ(pub_year.size(), 4);
    }
}

TEST(MultisetTest, HandlesNonUniqueElements)
{
    std::multiset<int> fib{1, 1, 2, 3, 5};
    EXPECT_TRUE(fib.size() == 5);
}

TEST(MultisetTest, CountReturnsVauesGreaterthanOne)
{
    {
        std::multiset<int> fib{1, 1, 2, 3, 5};
        EXPECT_TRUE(fib.count(1) == 2);
    }

    {
        std::multiset<int> fib{1, 1, 2, 3, 5};
        auto [begin, end] = fib.equal_range(1);

        EXPECT_TRUE(*begin == 1);
        ++begin;
        EXPECT_TRUE(*begin == 1);
        ++begin;
        EXPECT_TRUE(begin == end);
    }
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}