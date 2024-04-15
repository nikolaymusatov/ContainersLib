#include "test_s21_main.h"

TEST(constructor_with_size, test_0) {
  try {
    s21::vector<double> vector(10);
    ASSERT_EQ(vector.size(), 10);
    ASSERT_EQ(vector.capacity(), 10);
  } catch (const std::bad_alloc &e) {
    ASSERT_TRUE(false);
  }
}

TEST(constructor_with_size, test_1) {
  try {
    s21::vector<double> vector(0);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
  } catch (const std::bad_alloc &e) {
    ASSERT_TRUE(false);
  }
}

TEST(constructor_with_initilized_list, test_0) {
  const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
  s21::vector<int> vector(init_list);
  ASSERT_EQ(vector.size(), 5);
  ASSERT_EQ(vector.capacity(), 5);
}

TEST(copy_constructor, test_0) {
  const std::initializer_list<double> init_list = {1, 2, 3, 4, 5};
  try {
    s21::vector<double> vector(init_list);
    s21::vector<double> copy_vector(vector);
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 5);
    ASSERT_EQ(copy_vector.size(), 5);
    ASSERT_EQ(copy_vector.capacity(), 5);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list.begin()[i]);
      ASSERT_EQ(copy_vector.at(i), init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(move_constructor, test_0) {
  const std::initializer_list<double> init_list = {1, 2, 3, 4, 5};
  try {
    std::vector<double> vector(init_list);
    std::vector<double> dest_vector(std::move(vector));
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    ASSERT_EQ(dest_vector.size(), 5);
    ASSERT_EQ(dest_vector.capacity(), 5);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(dest_vector.at(i), init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}
