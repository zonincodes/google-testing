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

// for_each

TEST(ForEach, AppliesSomeUserDefinedFunction)
{
    vector<string> words{"David", "Donald", "Doo"};
    size_t number_of_Ds{};
    const auto count_Ds = [&number_of_Ds](const auto& word){
        if(word.empty()) return;
        if(word[0] == 'D') ++number_of_Ds;
    };

    for_each(words.cbegin(), words.cend(), count_Ds);
    EXPECT_EQ(number_of_Ds, 3);
}

TEST(ForEachN, AlgoAppliesSomeUserDefinedFunctionToElem)
{
    vector<string> words{"ear", "egg", "elephant"};
    size_t characters{};
    const auto count_characters = [&characters](const auto& word){
        characters += word.size();
    };

    for_each_n(words.cbegin(), words.size(), count_characters);
    EXPECT_EQ(characters, 14);
}

TEST(Find, FindFindIfFindIfNot)
{
    vector<string>words{"fiffer", "feffer", "feff"};
    const auto find_result = find(words.cbegin(), words.cend(), "feff");
    EXPECT_EQ(*find_result, words.back());

    //find_if
    const auto defends_digital_privacy = [](const auto& word){
        return string::npos != word.find("eff");
    };
    const auto find_if_result = find_if(words.cbegin(), words.cend(), defends_digital_privacy);
    EXPECT_EQ(*find_if_result, "feffer");

    const auto find_if_not_result = find_if_not(words.cbegin(), words.cend(), defends_digital_privacy);

    EXPECT_EQ(*find_if_not_result, words.front());
}

// find_end

TEST(FindEnd, ComplexityQuadratic)
{
    vector<string> words1 {"Goat", "girl", "googoo", "goggles" };
    vector<string> words2 {"girl", "googoo"};

    const auto find_end_result1 = find_end(words1.cbegin(), words1.cend(), words2.cbegin(), words2.cend());

    EXPECT_EQ(*find_end_result1, words1[1]);

    const auto has_length = [](const auto& word, const auto& len){
        return word.length() == len;
    };

    vector<size_t> sizes{4, 6};
    const auto find_end_result2 = find_end(words1.cbegin(), words1.cend(), sizes.cbegin(), sizes.cend(), has_length);

    EXPECT_EQ(*find_end_result2, words1[1]);
}

TEST(FindFirst, QuadraticComplexity)
{
    vector<string> words{"Hen", "in", "a", "hat"};
    vector<string> indefinite_articles{"a", "an"};
    const auto find_first_of_result = find_first_of(words.cbegin(), words.cend(), indefinite_articles.cbegin(), indefinite_articles.cend());
    EXPECT_EQ(*find_first_of_result, words[2]);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

