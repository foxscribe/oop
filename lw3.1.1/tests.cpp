#include <gtest/gtest.h>
#include "TVSet.hpp"

class TVSetTest : public ::testing::Test
{
protected:
    TVSet tv;

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(TVSetTest, InitialState)
{
    EXPECT_FALSE(tv.IsTurnedOn());
    EXPECT_EQ(0, tv.GetChannel());
    EXPECT_EQ(0, tv.GetLastChannel());
}

TEST_F(TVSetTest, TurnOnFirstTime)
{
    tv.TurnOn();
    EXPECT_TRUE(tv.IsTurnedOn());
    EXPECT_EQ(1, tv.GetChannel());
}

TEST_F(TVSetTest, TurnOff)
{
    tv.TurnOn();
    tv.TurnOff();
    EXPECT_FALSE(tv.IsTurnedOn());
    EXPECT_EQ(0, tv.GetChannel());
}

TEST_F(TVSetTest, TurnOnRestoresChannel)
{
    tv.TurnOn();
    tv.SetChannel(5);
    tv.TurnOff();
    tv.TurnOn();
    EXPECT_TRUE(tv.IsTurnedOn());
    EXPECT_EQ(5, tv.GetChannel());
}

TEST_F(TVSetTest, SetValidChannel)
{
    tv.TurnOn();
    tv.SetChannel(42);
    EXPECT_EQ(42, tv.GetChannel());
    EXPECT_EQ(1, tv.GetLastChannel());
}

TEST_F(TVSetTest, SetChannelTooHigh)
{
    tv.TurnOn();
    EXPECT_THROW(tv.SetChannel(100), std::exception);
    EXPECT_EQ(1, tv.GetChannel());
}

TEST_F(TVSetTest, SetChannelZero)
{
    tv.TurnOn();
    EXPECT_THROW(tv.SetChannel(0), std::exception);
    EXPECT_EQ(1, tv.GetChannel());
}

TEST_F(TVSetTest, SetChannelNegative)
{
    tv.TurnOn();
    EXPECT_THROW(tv.SetChannel(-5), std::exception);
    EXPECT_EQ(1, tv.GetChannel());
}

TEST_F(TVSetTest, SetChannelWhenOff)
{
    EXPECT_THROW(tv.SetChannel(5), std::exception);
    EXPECT_EQ(0, tv.GetChannel());
}

TEST_F(TVSetTest, SelectPreviousChannelBasic)
{
    tv.TurnOn();
    tv.SetChannel(2);
    tv.SetChannel(5);
    tv.SelectPreviousChannel();
    EXPECT_EQ(2, tv.GetChannel());
    EXPECT_EQ(5, tv.GetLastChannel());
}

TEST_F(TVSetTest, SelectPreviousChannelNoHistory)
{
    tv.TurnOn();
    EXPECT_THROW(tv.SelectPreviousChannel(), std::exception);
    EXPECT_EQ(1, tv.GetChannel());
}

TEST_F(TVSetTest, SelectPreviousChannelWhenOff)
{
    tv.TurnOn();
    tv.SetChannel(10);
    tv.TurnOff();
    EXPECT_THROW(tv.SelectPreviousChannel(), std::exception);
}

TEST_F(TVSetTest, PreviousChannelPreservedAfterOff)
{
    tv.TurnOn();
    tv.SetChannel(10);
    tv.TurnOff();
    tv.TurnOn();
    tv.SelectPreviousChannel();
    EXPECT_EQ(1, tv.GetChannel());
}

TEST_F(TVSetTest, GetLastChannel)
{
    tv.TurnOn();
    EXPECT_EQ(0, tv.GetLastChannel());
    tv.SetChannel(7);
    EXPECT_EQ(1, tv.GetLastChannel());
    tv.SetChannel(15);
    EXPECT_EQ(7, tv.GetLastChannel());
}

TEST_F(TVSetTest, TurnOnMultipleTimesSameChannel)
{
    tv.TurnOn();
    tv.TurnOff();
    tv.TurnOn();
    EXPECT_EQ(1, tv.GetChannel());
    tv.TurnOff();
    tv.TurnOn();
    EXPECT_EQ(1, tv.GetChannel());
}

TEST_F(TVSetTest, ChannelMinimum)
{
    tv.TurnOn();
    tv.SetChannel(1);
    EXPECT_EQ(1, tv.GetChannel());
}

TEST_F(TVSetTest, ChannelMaximum)
{
    tv.TurnOn();
    tv.SetChannel(99);
    EXPECT_EQ(99, tv.GetChannel());
}

TEST_F(TVSetTest, ChannelJustAboveMax)
{
    tv.TurnOn();
    EXPECT_THROW(tv.SetChannel(100), std::exception);
}

TEST_F(TVSetTest, SelectPreviousSwaps)
{
    tv.TurnOn();
    tv.SetChannel(3);
    tv.SetChannel(7);
    tv.SelectPreviousChannel();
    EXPECT_EQ(3, tv.GetChannel());
    EXPECT_EQ(7, tv.GetLastChannel());
    tv.SelectPreviousChannel();
    EXPECT_EQ(7, tv.GetChannel());
    EXPECT_EQ(3, tv.GetLastChannel());
}

TEST_F(TVSetTest, TurnOnWhenAlreadyOn)
{
    tv.TurnOn();
    tv.SetChannel(5);
    tv.TurnOn();
    EXPECT_TRUE(tv.IsTurnedOn());
    EXPECT_EQ(5, tv.GetChannel());
}

TEST_F(TVSetTest, TurnOffWhenAlreadyOff)
{
    tv.TurnOff();
    EXPECT_FALSE(tv.IsTurnedOn());
    EXPECT_EQ(0, tv.GetChannel());
}

TEST_F(TVSetTest, Channel99Then100)
{
    tv.TurnOn();
    tv.SetChannel(99);
    EXPECT_EQ(99, tv.GetChannel());
    EXPECT_THROW(tv.SetChannel(100), std::exception);
    EXPECT_EQ(99, tv.GetChannel());
}


TEST_F(TVSetTest, GetChannelReturnsZeroWhenOff)
{
    tv.TurnOn();
    tv.SetChannel(42);
    tv.TurnOff();
    EXPECT_EQ(0, tv.GetChannel());
}

TEST_F(TVSetTest, SetSameChannelTwice)
{
    tv.TurnOn();
    tv.SetChannel(5);
    EXPECT_EQ(1, tv.GetLastChannel());
    tv.SetChannel(5);
    EXPECT_EQ(5, tv.GetChannel());
    EXPECT_EQ(5, tv.GetLastChannel());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
