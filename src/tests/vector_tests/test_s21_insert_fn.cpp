#include "test_s21_main.h"

TEST(insert_function, test_0) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const std::initializer_list<int> init_list_1 = {21, 1, 2, 3, 4, 5};
    s21::vector<int> vector(init_list);
    s21::vector<int>::iterator itr = vector.begin();
    s21::vector<int>::iterator itr1 = vector.insert(itr, 21);
    ASSERT_EQ(*itr1, 21);
    ASSERT_EQ(vector.size(), 6);
    ASSERT_EQ(vector.capacity(), 10);
    for (int i = 0; i < init_list_1.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list_1.begin()[i]);
    }
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(insert_function, test_1) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const std::initializer_list<int> init_list_1 = {1, 2, 3, 21, 4, 5};
    s21::vector<int> vector(init_list);
    s21::vector<int>::iterator itr = vector.begin() + 3;
    s21::vector<int>::iterator itr1 = vector.insert(itr, 21);
    ASSERT_EQ(*itr1, 21);
    ASSERT_EQ(vector.size(), 6);
    ASSERT_EQ(vector.capacity(), 10);
    for (int i = 0; i < init_list_1.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list_1.begin()[i]);
    }
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(insert_function, test_2) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const std::initializer_list<int> init_list_1 = {1, 2, 3, 4, 5, 21};
    s21::vector<int> vector(init_list);
    s21::vector<int>::iterator itr = vector.begin() + 5;
    s21::vector<int>::iterator itr1 = vector.insert(itr, 21);
    ASSERT_EQ(*itr1, 21);
    ASSERT_EQ(vector.size(), 6);
    ASSERT_EQ(vector.capacity(), 10);
    for (int i = 0; i < init_list_1.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list_1.begin()[i]);
    }
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(insert_function, test_3) {
  try {
    s21::vector<int> vector;
    s21::vector<int>::iterator itr = vector.begin();
    s21::vector<int>::iterator itr1 = vector.insert(itr, 21);
    ASSERT_EQ(*itr1, 21);
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
    ASSERT_EQ(vector.at(0), 21);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}