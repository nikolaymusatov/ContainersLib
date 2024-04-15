#include "test_s21_main.h"

TEST(erase_function, test_0) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    s21::vector<int> vector(init_list);
    vector.erase(vector.begin() + 2);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 5);
    ASSERT_EQ(vector.at(2), 4);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(erase_function, test_1) {
  try {
    const std::initializer_list<int> init_list = {1};
    s21::vector<int> vector(init_list);
    vector.erase(vector.begin());
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 1);
    ASSERT_EQ(vector[0], 1);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(erase_function, test_2) {
  try {
    s21::vector<int> vector;
    vector.erase(vector.begin());
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}