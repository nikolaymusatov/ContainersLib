#include "test_s21_main.h"

TEST(access_data_fn, test_0) {
  s21::vector<double> vector(10);
  vector.push_back(14);
  ASSERT_EQ(vector.size(), 11);
  ASSERT_EQ(vector.capacity(), 20);
  ASSERT_EQ(*(vector.data() + 10), 14);
}

TEST(access_data_fn, test_1) {
  s21::vector<double> vector;
  ASSERT_EQ(vector.size(), 0);
  ASSERT_EQ(vector.capacity(), 0);
  ASSERT_EQ(vector.data(), nullptr);
}

TEST(access_data_fn, test_2) {
  std::vector<double> vector(1);
  ASSERT_EQ(vector.size(), 1);
  ASSERT_EQ(vector.capacity(), 1);
  *vector.data() = 5;
  ASSERT_EQ(*vector.data(), 5);
}