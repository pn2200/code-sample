#include <fstream>
#include "gtest/gtest.h"
#include "Cmd.hpp"

TEST(CmdTest, FileNotFound)
{
    Cmd c;
    ASSERT_FALSE(c.Add("/dev/null/foo.txt"));
    c.Quit();
}

TEST(CmdTest, FileFound)
{
    // Arrange.
    auto filename("src/EventBus.hpp");

    Cmd c;
    ASSERT_TRUE(c.Add(filename));
    c.Quit();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
