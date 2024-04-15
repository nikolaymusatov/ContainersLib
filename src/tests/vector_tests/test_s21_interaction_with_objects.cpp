#include "test_s21_main.h"

TEST(interaction_with_objects, test_0) {
  try {
    std::initializer_list<int> list = {1, 2, 3, 4, 5};
    s21::vector<int> v(list);
    s21::vector<s21::vector<int>> vector;
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    vector.push_back(v);
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
    for (int i = 0; i < list.size(); ++i) {
      ASSERT_EQ(vector.at(0).at(i), list.begin()[i]);
    }
    for (int i = 0; i < list.size(); ++i) {
      ASSERT_EQ(v.at(i), list.begin()[i]);
    }
    ASSERT_EQ(v.size(), 5);
    ASSERT_EQ(v.capacity(), 5);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(interaction_with_objects, test_1) {
  try {
    std::initializer_list<int> list = {1, 2, 3, 4, 5};
    s21::vector<int> v(list);
    s21::vector<s21::vector<int>> vector;
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    vector.push_back(std::move(v));
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
    for (int i = 0; i < list.size(); ++i) {
      ASSERT_EQ(vector.at(0).at(i), list.begin()[i]);
    }
    ASSERT_EQ(v.size(), 0);
    ASSERT_EQ(v.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}
