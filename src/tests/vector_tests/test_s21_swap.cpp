#include "test_s21_main.h"

TEST(swap_function, test_0) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    s21::vector<int> vector(init_list);
    s21::vector<int> vector1(init_list);
    vector.swap(vector1);
    for (int i = 0; i < vector.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list.begin()[i]);
    }
    for (int i = 0; i < vector1.size(); ++i) {
      ASSERT_EQ(vector1.at(i), init_list.begin()[i]);
    }
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector1.size(), 5);
    ASSERT_EQ(vector.capacity(), 5);
    ASSERT_EQ(vector1.capacity(), 5);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(swap_function, test_1) {
  try {
    const std::initializer_list<int> init_list = {1};
    s21::vector<int> vector(init_list);
    s21::vector<int> vector1(init_list);
    vector.swap(vector1);
    for (int i = 0; i < vector.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list.begin()[i]);
    }
    for (int i = 0; i < vector1.size(); ++i) {
      ASSERT_EQ(vector1.at(i), init_list.begin()[i]);
    }
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector1.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
    ASSERT_EQ(vector1.capacity(), 1);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(swap_function, test_3) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const std::initializer_list<int> init_list1 = {1};
    s21::vector<int> vector(init_list1);
    s21::vector<int> vector1(init_list);
    vector.swap(vector1);
    for (int i = 0; i < vector.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list.begin()[i]);
    }
    for (int i = 0; i < vector1.size(); ++i) {
      ASSERT_EQ(vector1.at(i), init_list1.begin()[i]);
    }
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector1.size(), 1);
    ASSERT_EQ(vector.capacity(), 5);
    ASSERT_EQ(vector1.capacity(), 1);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(swap_function, test_4) {
  try {
    s21::vector<int> vector;
    s21::vector<int> vector1;
    vector.swap(vector1);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector1.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    ASSERT_EQ(vector1.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}