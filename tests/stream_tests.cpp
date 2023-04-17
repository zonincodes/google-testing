#include <gtest/gtest.h>
#include <string>
#include <sstream>

TEST(Zero, RandomTest)
{
    EXPECT_EQ(1, 1);
}

TEST(OstringStream, ProducesStringsWithStr)
{
    std::ostringstream ss;

    ss << "By Grabthar's hammer, ";
    ss << "by the suns of Worvan. ";
    ss << "You shall be avenged.";

    const auto lazarous = ss.str();
    ss.str("I am Groot.");
    const auto groot = ss.str();

    EXPECT_EQ(lazarous, "By Grabthar's hammer, by the suns of Worvan. You shall be avenged.");
    EXPECT_EQ(groot, "I am Groot.");
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}