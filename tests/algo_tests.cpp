#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



// all of test
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


// any_of
// determines Whether any elments in a sequence meets user-specified criteria

// the algorithm returns false if the target sequnce is empty or if pred s true for any element;

TEST(AnyOf, AnyOfTheElementIsTrue)
{
    vector<string> words{"Barber", "baby", "bubbles"};

    const auto contains_bar = [](const auto& word){
        return word.find("Bar") != string::npos;
    };

    EXPECT_TRUE(any_of(words.cbegin(), words.cend(), contains_bar));

    const auto is_empty = [](const auto& word){
        return word.empty();
    };

    EXPECT_FALSE(any_of(words.cbegin(), words.cend(), is_empty));
}

// none_of 
// The none_of algorith determines whether noelemnt in a sequence meets some user-specified criteria.

TEST(NoneOf, NoElementsInSequence)
{
    vector<string> words{"Carmel", "on", "the", "ceiling"};

    const auto is_hump_day = [](const auto& word){
        return word == "hump day";
    };

    EXPECT_TRUE(none_of(words.cbegin(), words.cend(), is_hump_day));

    const auto is_definate_article =[](const auto& word){
        return word == "the" || word == "ye";
    };

    EXPECT_FALSE(none_of(words.cbegin(), words.cend(), is_definate_article));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}