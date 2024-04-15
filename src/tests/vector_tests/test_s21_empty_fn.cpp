#include "test_s21_main.h"

TEST(empty_function, test_0) {
  s21::vector<int> vector;
  EXPECT_TRUE(vector.empty());
}

TEST(empty_function, test_1) {
  s21::vector<int> vector(10);
  EXPECT_FALSE(vector.empty());
}