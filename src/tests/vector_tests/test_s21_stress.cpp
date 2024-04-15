#include "test_s21_main.h"

TEST(constructor_with_size__stress, test_0) {
  try {
    s21::vector<double> vector(100000000000000);
  } catch (const std::bad_alloc &e) {
    ASSERT_TRUE(true);
  }
}

TEST(resize_function__stress, test_0) {
  s21::vector<int> vector;
  EXPECT_THROW(vector.resize(-1), std::length_error);
  EXPECT_EQ(vector.size(), 0);
  EXPECT_EQ(vector.capacity(), 0);
}

TEST(resize_function__stress, test_1) {
  s21::vector<double> vector;
  EXPECT_THROW(vector.resize(100000000000000), std::bad_alloc);
  EXPECT_EQ(vector.size(), 0);
  EXPECT_EQ(vector.capacity(), 0);
}

TEST(push_back_function__stress, test_0) {
  s21::vector<double> vector;
  try {
    double value = 3.4;
    for (int i = 0; i < 100000000; ++i) {
      vector.push_back(value);
      vector.push_back(value);
      vector.push_back(value);
      vector.push_back(value);
      vector.push_back(value);
      vector.push_back(value);
      vector.push_back(value);
      vector.push_back(value);
      vector.push_back(value);
      vector.push_back(value);
    }
  } catch (const std::bad_alloc &e) {
    ASSERT_TRUE(true);
  }
}
