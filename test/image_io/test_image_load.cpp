#include <gtest/gtest.h>
#include <iostream>

#include "image_io/Image.h"


TEST(LoadImage, Constructor)
{
    auto img = Image("test_load.jpg");
    EXPECT_EQ(img.width(), 172);
    EXPECT_EQ(img.height(), 178);
}

TEST(LoadImage, Method)
{
    auto img = Image();
    img.load("test_load.jpg");
    EXPECT_EQ(img.width(), 172);
    EXPECT_EQ(img.height(), 178);
}

/// testload of an jpg
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
