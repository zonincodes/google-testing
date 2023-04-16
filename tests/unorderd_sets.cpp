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
        0x8c, 0xe2, 0xb2, 0x2a 
    };

    auto itr = mission.begin();
    std::advance(itr, 4);
    EXPECT_EQ(*itr, 0x49);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}