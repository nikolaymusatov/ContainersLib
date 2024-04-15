#include "test_s21_main.h"

TEST(shrink_to_fit_function, test_0) {
  try {
    s21::vector<std::string> vector(4);
    vector.push_back("a");
    ASSERT_EQ(vector.capacity(), 8);
    vector.shrink_to_fit();
    ASSERT_EQ(vector.capacity(), 5);
    vector.push_back("b");
    ASSERT_EQ(vector.capacity(), 10);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(shrink_to_fit_function, test_1) {
  try {
    s21::vector<std::string> vector;
    ASSERT_EQ(vector.capacity(), 0);
    vector.shrink_to_fit();
    ASSERT_EQ(vector.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(shrink_to_fit_function, test_2) {
  try {
    s21::vector<std::string> vector(4);
    vector.push_back("a");
    vector.shrink_to_fit();
    ASSERT_EQ(vector.capacity(), 5);
    vector.push_back("b");
    ASSERT_EQ(vector.capacity(), 10);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}