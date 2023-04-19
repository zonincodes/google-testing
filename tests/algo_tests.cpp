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
// adjacent find
// finds the first repeat in a sequnce
TEST(AdjacentFind, FindFirstRepeat)
{
    vector<string> words{"Icabod", "is", "itchy"};
    const auto first_letters_match = [](const auto& word1, const auto& word2){
        if(word1.empty() || word2.empty()) return false;
        return word1.front() == word2.front();
    };
    const auto adjacent_find_result = adjacent_find(words.cbegin(), words.cend(), first_letters_match);
    
    EXPECT_EQ(*adjacent_find_result, words[1]);
}

//count algorithm
TEST(Count, SumOfElemMatchingCriteria)
{
    vector<string> words{"jelly", "jar", "and", "jam"};
    const auto n_ands = count(words.cbegin(), words.cend(), "and");
    EXPECT_EQ(n_ands, 1);

    const auto contains_a = [](const auto& word){
        return word.find('a') != string::npos;
    };

    const auto count_if_result = count_if(words.cbegin(), words.cend(), contains_a);

    EXPECT_EQ(count_if_result, 3);
}

// mismatch
TEST(Mismatch, Elem1MatchesElem2)
{
   vector<string> words1{"Kitten", "Kangaroo", "Kick"};
   vector<string> words2{"Kitten", "bandicoot", "roundhouse"};  
   const auto mismatch_result1 = mismatch(words1.cbegin(), words1.cend(), words2.cbegin(), words2.cend());

   EXPECT_EQ(*mismatch_result1.first, "Kangaroo");
   EXPECT_EQ(*mismatch_result1.second, "bandicoot");

   const auto second_letter_matches = [](const auto& word1, const auto& word2){
    if(word1.size() < 2)
        return false;
    if (word1.size() < 2)
        return false;
    return word1[1] == word2[1];

   };

   const auto mismatch_result2 = mismatch(words1.cbegin(), words1.cend(), words2.cbegin(), second_letter_matches);

   EXPECT_EQ(*mismatch_result2.first, "Kick");
   EXPECT_EQ(*mismatch_result2.second, "roundhouse");
}
// Mutating Sequence operation
// is an algorithm that performs computation over a sequence and is allowed to modify the sequence in some way
TEST(MutatingSequenceOperation, Copy) // linear complecity
{
    vector<string> words1{ "and", "prosper"};
    vector<string> words2{"Live", "long"};

    copy(words1.cbegin(), words1.cend(), back_inserter(words2));
    vector<string> expected {"Live", "long", "and", "prosper"};
    EXPECT_EQ(words2, expected);
}

// copy n
TEST(MutatingSequenceOperation, CopnN)
{
    vector<string> words1{"on", "the", "wind"};
    vector<string> words2{"I'm", "a", "leaf"};

    copy_n(words1.cbegin(), words1.size(), back_inserter(words2));
    vector<string> expected{"I'm", "a", "leaf", "on", "the","wind"};
    EXPECT_EQ(words2, expected);
}

// copy_backword
// copies the reverse of one sequence into another
// linear complecity

TEST(MutatingSequenceOperation, CopyBackward)
{
    vector<string> words1{"A", "man", "a", "plan", "a", "bran", "muffin"};
    vector<string> words2{"a", "canal", "Panama"};
    const auto result = copy_backward(words2.cbegin(), words2.cend(), words1.end());
    vector<string> expected{"A", "man", "a", "plan", "a", "canal", "Panama"};

    EXPECT_TRUE(words1 == expected);
}

// Move
// Moves one sequence inot another.
// examples

struct MoveDetector {
    MoveDetector() : owner{ true} {}
    MoveDetector(const MoveDetector&) = delete;
    MoveDetector& operator=(const MoveDetector&& o) = delete;
    MoveDetector& operator=(MoveDetector&& o){
        o.owner = false;
        owner = true;
        return *this;
    }
    bool owner;
};

TEST(MutatingSequenceOperation, Move)
{
    vector<MoveDetector> detectors1(2);
    vector<MoveDetector> detectors2(2);
    move(detectors1.begin(), detectors1.end(), detectors2.begin());

    EXPECT_FALSE(detectors1[0].owner);
    EXPECT_FALSE(detectors1[1].owner);
    EXPECT_TRUE(detectors2[0].owner);
    EXPECT_TRUE(detectors2[1].owner);
}

TEST(MutatingSequenceOperation, MoveBackward)
{
    vector<MoveDetector> detectors1(2);
    vector<MoveDetector> detectors2(2);
    move_backward(detectors1.begin(), detectors1.end(), detectors2.end());
    EXPECT_FALSE(detectors1[0].owner);
    EXPECT_FALSE(detectors1[1].owner);
    EXPECT_TRUE(detectors2[0].owner);
    EXPECT_TRUE(detectors2[1].owner);
}

//  swap_ranges
TEST(MutatingSequenceOperation, SwapRanges)
{
    vector<string> words1{"The", "king", "is", "dead."};
    vector<string> words2{"Long", "live", "the", "king."};
    vector<string> expected1 = words2;
    vector<string> expected2 = words1;

    swap_ranges(words1.begin(), words1.end(), words2.begin());
    EXPECT_EQ(words1, expected1);
    EXPECT_EQ(words2, expected2);
}

// Replace

TEST(MutatingSequenceOperation, Replace)
{
    using namespace std::literals;
    vector<string> words1{"There", "is", "no", "try"};
    replace(words1.begin(), words1.end(), "try"sv, "spoon"sv);
    vector<string> expected1{"There", "is", "no", "spoon"};
    EXPECT_EQ(words1, expected1);

    const vector<string> words2{"There", "is", "no", "spoon"};
    vector<string> words3{"There", "is", "no", "spoon"};
    auto has_two_os = [](const auto& x){
        return count(x.begin(), x.end(), 'o') == 2;
    };

    replace_copy_if(words2.begin(), words2.end(), words3.begin(), has_two_os, "try"sv);

    vector<string> expected2{"There", "is",  "no", "try"};
    EXPECT_EQ(words3, expected2);
}

// Sorting and relatated Opearations
TEST(SortingAndRelatedOperations, Sort) // quasilinear complexity
{
    string goat_grass{"spoilage"};
    sort(goat_grass.begin(), goat_grass.end());
    string expected{"aegilops"};
    EXPECT_TRUE(goat_grass == expected);
}


// main
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

