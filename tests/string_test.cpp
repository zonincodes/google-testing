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

TEST(StdString, SupportsCopyConstructing)
{
    std::string word("catwampus");
    EXPECT_EQ(std::string(word), "catwampus");
}

TEST(StdString, SupportsMoveConstructing)
{
    std::string word("catawampus");
    EXPECT_EQ(std::string(move(word)), "catawampus");
}

TEST(StdString, SupportsConstructingFromSubStrings)
{
    std::string word("catawampus");
    EXPECT_EQ(std::string(word, 0, 3), "cat");
    EXPECT_EQ(std::string(word, 4), "wampus");
}
/*
The STL provides four basic_string specialization in the <string> header.
std::string for char is used for large chater sets like ASCII
std::wstring for wchar_t is large enough to contain the largest charater of the implementaion's locale.
std::u16string for char16_t is used for character sets like UTF-16.
std::u32string for char32_t is used for character sets like UTF_32.
*/

TEST(ReplacingElements, WorksWithSubstitution)
{
    std::string word("substitution");
    { 
        word.replace(word.begin()+9, word.end(), "e");
        EXPECT_EQ(word, "substitute");
    }
    
}

TEST(ReplacingElements, ReplacingWithTwoRanges)
{
    std::string word("substitution");
    std::string other("innuendo");
    word.replace(word.begin(), word.begin() + 3, other.begin(), other.begin() + 2);
    EXPECT_EQ(word, "institution");
}

TEST(ReplacingElements, ReplaceWithIndexLengthAndString)
{

    std::string word = "substitution";
    std::string other("vers");
    word.replace(3, 6, other);
    EXPECT_EQ(word, "subversion");
}


TEST(Search, LocatesSubstringsFromStrings)
{
    using namespace std::literals::string_literals;
    std::string word("pizzazz");
    EXPECT_EQ(word.find("zz"s), 2);
}

TEST(Search, AccepstPositionArgument)
{
    using namespace std::literals::string_literals;
    std::string word("pizzazz");
    EXPECT_EQ(word.find("zz"s, 3), 5);
}

TEST(Search, LocatesSubStringsFromChar)
{
    using namespace std::literals::string_literals;
    std::string word("pizzazz");
    EXPECT_EQ(word.find("zaz"), 3);
}











int main (int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
