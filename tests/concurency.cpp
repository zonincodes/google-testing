#include <gtest/gtest.h>
#include <future>
#include <string>

using namespace std;

TEST(Asynchronous, ReturnsValidFuture)
{
    using namespace literals::string_literals;
    auto the_future =async([]{ return "female"s; });
    EXPECT_TRUE(the_future.valid());
}

TEST(Asynchronous, FutureInvalidByDefault)
{
    future<bool> default_future;
    EXPECT_FALSE(default_future.valid());
}

TEST(Asynchronous, ReturnsTheValueOfFunctionObj)
{
    using namespace literals::string_literals;
    auto the_future = async([]
                            { return "female"s; });
    EXPECT_TRUE(the_future.get() == "female");
}

// *** error ***

TEST(Asynchronous, GetMayThrow)
{
    auto ghostrider = async([]{ throw runtime_error{"The pattern is full."};});

    EXPECT_THROW(ghostrider.get(), runtime_error);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}