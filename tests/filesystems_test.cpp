#include <gtest/gtest.h>
#include <filesystem>
TEST(Test, Zero)
{
    EXPECT_EQ(1, 1);
}

/*
A file is a filesystem object that supports unput and ouput and holds data. 
*/

TEST(FileSystems, ConstructTwoPaths)
{
    std::filesystem::path empty_path;
    std::filesystem::path shadow_path{"/etc/shadow"};

    EXPECT_TRUE(empty_path.empty());
    EXPECT_EQ(shadow_path, "/etc/shadow");
}

TEST(FileSystems, IspectingFilesType)
{
    std::filesystem::path nix_path{R"(/bin/bash)"};
    EXPECT_TRUE(std::filesystem::is_regular_file(nix_path));
    EXPECT_FALSE(std::filesystem::is_directory(nix_path));
}
int main (int argc, char**  argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}