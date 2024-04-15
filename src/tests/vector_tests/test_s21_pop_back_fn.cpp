#include "test_s21_main.h"

TEST(pop_back_function, test_0) {
  try {
    s21::vector<int> vector({1, 2, 3, 4});
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 4);
    vector.push_back(21);
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 8);
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    ASSERT_EQ(vector.size(), 2);
    ASSERT_EQ(vector.capacity(), 8);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(pop_back_function, test_1) {
  try {
    s21::vector<s21::vector<int>> vector(4);
    s21::vector<int> tmp_vector({1, 2, 3, 4});
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 4);
    vector.push_back(tmp_vector);
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 8);
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    ASSERT_EQ(vector.size(), 2);
    ASSERT_EQ(vector.capacity(), 8);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(pop_back_function, test_2) {
  try {
    s21::vector<int> vector;
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    vector.pop_back();
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}
