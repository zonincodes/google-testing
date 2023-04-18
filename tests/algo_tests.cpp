#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


TEST(AllOf, AllOf)
{
    vector<string> words{"Auntie", "Anne's", "alligator"};

    const auto starts_with_a = [](const auto& word){
        if(word.empty()) return false;
        return word[0] == 'A' || word[0] == 'a';
    };

    EXPECT_TRUE(all_of(words.cbegin(), words.cend(), starts_with_a));
    

    //
    const auto has_length_six = [](const auto& word){
        return word.length() == 6;
    };

    EXPECT_FALSE(all_of(words.cbegin(), words.cend(), has_length_six));
}





int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}