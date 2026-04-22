/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
    PasswordTest() {}
    virtual ~PasswordTest() {}
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
    ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}

TEST(PasswordTest, repeated_letters)
{
    Password my_password;
    ASSERT_EQ(2, my_password.count_leading_characters("ZZz"));
}

TEST(PasswordTest, lower_case_password)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("zzz"));
}

TEST(PasswordTest, empty_string)
{
    Password my_password;
    ASSERT_EQ(0, my_password.count_leading_characters(""));
}

TEST(PasswordTest, mixed_case_Aa)
{
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("Aa"));
}

TEST(PasswordTest, mixed_case_aA)
{
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("aA"));
}

TEST(PasswordTest, only_upper)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("ZZZ"));
}

TEST(PasswordTest, no_letters)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("1234!@#"));
}