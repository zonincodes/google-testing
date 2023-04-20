#include <gtest/gtest.h>
#include <future>
#include <string>

using namespace std;

TEST(Asyncronus, ReturnsValidFuture)
{
    using namespace literals::string_literals;
    auto the_future =async([]{ return "female"s; });
    EXPECT_TRUE(the_future.valid());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}