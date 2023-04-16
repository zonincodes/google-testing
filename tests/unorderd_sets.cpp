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

TEST(StdDistance, ReturnsTheNumberOfElementsBetweenIterators)
{
    std::vector<unsigned char> mission{
        0x9e, 0xc4, 0xc1, 0x29,
        0x49, 0xa4, 0xf3, 0x14,
        0x74, 0xf2, 0x99, 0x05,
        0x8c, 0xe2, 0xb2, 0x2a};
    
    auto eighth =std::next(mission.begin(), 8);
    auto fifth = std::prev(eighth, 3);
    EXPECT_EQ(std::distance(fifth, eighth), 3);
}


// std::iter_swap
// The std::iter swap auxiliar iteratir function allows you to swap the values pointed to by two forward iterators itr and itr2:
TEST(StdIterSwap, SwapsPointedToElemets)
{
    std::vector<long> easy_as{3, 2, 1};
    std::iter_swap(easy_as.begin(), std::next(easy_as.begin(), 2));

    EXPECT_EQ(easy_as[0], 1);
    EXPECT_EQ(easy_as[1], 2);
    EXPECT_EQ(easy_as[2], 3);
}

struct Movable{
    Movable(int id): id{ id } {}
    Movable(Movable&& m){
        id = m.id;
        m.id = -1;
    }
    int id;
};

TEST(StdMakeMove, MoveIterators)
{
    std::vector<Movable> donor;
    donor.emplace_back(1);
    donor.emplace_back(2);
    donor.emplace_back(3);

    std::vector<Movable> recipient{
        std::make_move_iterator(donor.begin()),
        std::make_move_iterator(donor.end())
    };

    EXPECT_EQ(donor[0].id, -1);
    EXPECT_EQ(donor[1].id, -1);
    EXPECT_EQ(donor[2].id, -1);
    EXPECT_EQ(recipient[0].id, 1);
    EXPECT_EQ(recipient[1].id, 2);
    EXPECT_EQ(recipient[2].id, 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}