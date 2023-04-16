#include <string>
#include <gtest/gtest.h>

TEST(StdString, SupportsConstructingEmptyString)
{
    std::string cheese;
    EXPECT_TRUE(cheese.empty());
}

TEST(StdString, SupportsRepeatedCharacters)
{
    std::string roadside_assistance(3, 'A');
    EXPECT_EQ(roadside_assistance, "AAA");
}
int main (int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}