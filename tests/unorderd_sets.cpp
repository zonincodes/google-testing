#include <iostream>
#include <gtest/gtest.h>
#include <iterator>
#include <deque>
#include <forward_list>
TEST(InsertIterators, ConvertWritesIntoContainerInsertion)
{
    std::deque<int> dq;
    auto back_instr = std::back_inserter(dq);
    *back_instr = 2; //2
    ++back_instr;
    *back_instr = 4; // 2 4
    ++back_instr;

    auto front_instr = std::front_inserter(dq);
    *front_instr = 1; //1 3 4
    ++front_instr;

    auto instr = std::inserter(dq, dq.begin() + 2);
    *instr = 3; // 1 2 3 4
    instr++;

    EXPECT_TRUE(dq[0] == 1);
    EXPECT_TRUE(dq[1] == 2);
    EXPECT_TRUE(dq[2] == 3);
    EXPECT_TRUE(dq[3] == 4);
}


TEST(StdForwardList, BeginAndEndProvideIterators)
{
    const std::forward_list<int> easy_as{1, 2, 3};
    auto itr = easy_as.begin();
    EXPECT_EQ(*itr, 1);
    itr++;
    EXPECT_EQ(*itr, 2);
    itr++;
    EXPECT_EQ(*itr, 3);
    itr++;
    EXPECT_EQ(itr, easy_as.end());
}

TEST(StdAdvance, AdvanceModifiesInputIterators)
{
    std::vector<unsigned char> mission{
        0x9e, 0xc4, 0xc1, 0x29,
        0x49, 0xf2, 0x99, 0x05,
        0x74, 0xf2, 0x99, 0x05,
        0x8c, 0xe2, 0xb2, 0x2a 
    };

    auto itr = mission.begin();
    std::advance(itr, 4);
    EXPECT_EQ(*itr, 0x49);
    std::advance(itr, 4);
    EXPECT_EQ(*itr, 0x74);
    std::advance(itr, -8);
    EXPECT_EQ(*itr, 0x9e);
}


// std::next, std::prev auxiliary iterator functions are functions templates that compute offset from given iterator. They return a new iterator

TEST(StdNext, NextReturnsIteratorsAtGivenOffsets){
    std::vector<unsigned char> mission{
        0x9e, 0xc4, 0xc1, 0x29,
        0x49, 0xa4, 0xf3, 0x14,
        0x74, 0xf2, 0x99, 0x05,
        0x8c, 0xe2, 0xb2, 0x2a};
    
    auto itr1 = mission.begin();
    std::advance(itr1, 4);
    EXPECT_EQ(*itr1, 0x49);
    auto itr2 = std::next(itr1);
    EXPECT_EQ(*itr2, 0xa4);
    auto itr3 = std::next(itr1, 4);
    EXPECT_EQ(*itr3, 0x74);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}