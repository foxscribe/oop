#include <gtest/gtest.h>
#include <string>
#include "sort.hpp"

TEST(TemplateSortTest, IntTwoSort)
{
    int a = 9, b = 5;
    Sort2(a, b);
    EXPECT_EQ(a, 5);
    EXPECT_EQ(b, 9);
}

TEST(TemplateSortTest, IntTwoNoSort)
{
    int a = 5, b = 9;
    Sort2(a, b);
    EXPECT_EQ(a, 5);
    EXPECT_EQ(b, 9);
}

TEST(TemplateSortTest, FloatTwoSort)
{
    float a = 9.5, b = 9.2;
    Sort2(a, b);
    EXPECT_FLOAT_EQ(a, 9.2);
    EXPECT_FLOAT_EQ(b, 9.5);
}

TEST(TemplateSortTest, FloatTwoNoSort)
{
    float a = 5.2, b = 5.5;
    Sort2(a, b);
    EXPECT_FLOAT_EQ(a, 5.2);
    EXPECT_FLOAT_EQ(b, 5.5);
}

TEST(TemplateSortTest, CharTwoSort)
{
    char a = 'c', b = 'a';
    Sort2(a, b);
    EXPECT_EQ(a, 'a');
    EXPECT_EQ(b, 'c');
}

TEST(TemplateSortTest, CharTwoNoSort)
{
    char a = 'a', b = 'c';
    Sort2(a, b);
    EXPECT_EQ(a, 'a');
    EXPECT_EQ(b, 'c');
}

TEST(TemplateSortTest, StrTwoSort)
{
    std::string a = "qwerty", b = "dvorak";
    Sort2(a, b);
    EXPECT_EQ(a, "dvorak");
    EXPECT_EQ(b, "qwerty");
}

TEST(TemplateSortTest, StrTwoNoSort)
{
    char a = 'a', b = 'c';
    Sort2(a, b);
    EXPECT_EQ(a, 'a');
    EXPECT_EQ(b, 'c');
}

TEST(TemplateSortTest, CstrTwoSort)
{
    const char *a = "qwerty", *b = "dvorak";
    Sort2(a, b);
    EXPECT_STREQ(a, "dvorak");
    EXPECT_STREQ(b, "qwerty");
}

TEST(TemplateSortTest, CstrTwoNoSort)
{
    const char *a = "dvorak", *b = "qwerty";
    Sort2(a, b);
    EXPECT_STREQ(a, "dvorak");
    EXPECT_STREQ(b, "qwerty");
}

TEST(TemplateSortTest, CstrTwoSortRus)
{
    const char *a = "йцукен", *b = "абвгд";
    Sort2(a, b);
    EXPECT_STREQ(a, "абвгд");
    EXPECT_STREQ(b, "йцукен");
}

TEST(TemplateSortTest, CstrTwoNoSortRus)
{
    const char *a = "абвгд", *b = "йцукен";
    Sort2(a, b);
    EXPECT_STREQ(a, "абвгд");
    EXPECT_STREQ(b, "йцукен");
}

TEST(TemplateSortTest, CstrSortCutoff)
{
    const char *a = "qwerty", *b = "qwer";
    Sort2(a, b);
    EXPECT_STREQ(a, "qwer");
    EXPECT_STREQ(b, "qwerty");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
