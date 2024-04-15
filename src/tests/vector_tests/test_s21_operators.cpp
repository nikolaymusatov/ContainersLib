#include "test_s21_main.h"

TEST(assignment_operator, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    s21::vector<int> vector(init_list);
    s21::vector<int> new_vector = std::move(vector);
    ASSERT_EQ(new_vector.size(), 3);
    ASSERT_EQ(new_vector.capacity(), 3);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(new_vector.at(i), init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(assignment_operator, test_1) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    s21::vector<int> vector(init_list);
    s21::vector<int> new_vector(4);
    new_vector = std::move(vector);
    ASSERT_EQ(new_vector.size(), 3);
    ASSERT_EQ(new_vector.capacity(), 3);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(new_vector.at(i), init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(assignment_operator, test_2) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    s21::vector<int> vector(init_list);
    vector = std::move(vector);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(assignment_operator_not_bouds_checking, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    s21::vector<int> vector(init_list);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(vector[i], init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(assignment_operator_not_bouds_checking, test_1) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    s21::vector<int> vector(3);
    for (int i = 0; i < init_list.size(); ++i) {
      vector[i] = init_list.begin()[i];
      ASSERT_EQ(vector[i], init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}