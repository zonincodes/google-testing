#include <gtest/gtest.h>
#include <future>
#include <string>
#include <chrono>
#include <thread>
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

// *** wait_for ***

TEST(Asynchronous, WaitForIndicatesTaskIsReady)
{
    using namespace literals::chrono_literals;
    auto sleepy = async(launch::async, [] {this_thread::sleep_for(100ms); });
    const auto not_ready_yet = sleepy.wait_for(25ms);
    EXPECT_EQ(not_ready_yet, future_status::timeout);
    const auto totally_ready = sleepy.wait_for(100ms);
    EXPECT_EQ(totally_ready , future_status::ready);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}