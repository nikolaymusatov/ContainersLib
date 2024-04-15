#include "test_s21_main.h"

TEST(test_reserve_function, test_0) {
  try {
    s21::vector<std::string> vector(4);
    vector.push_back("a");
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 8);
    vector.reserve(100);
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 100);
    vector.push_back("b");
    ASSERT_EQ(vector.size(), 6);
    ASSERT_EQ(vector.capacity(), 100);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(test_reserve_function, test_1) {
  try {
    s21::vector<std::string> vector(4);
    vector.reserve(100);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 100);
    vector.reserve(50);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 100);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(test_reserve_function, test_2) {
  try {
    s21::vector<std::string> vector(4);
    vector.reserve(0);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 4);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(test_reserve_function, test_3) {
  try {
    s21::vector<std::string> vector(4);
    EXPECT_THROW(vector.reserve(-1), std::length_error);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}