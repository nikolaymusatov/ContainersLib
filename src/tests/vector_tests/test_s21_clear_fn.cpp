#include "test_s21_main.h"

TEST(clear_function, test_0) {
  try {
    s21::vector<int> vector(4);
    vector.clear();
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(clear_function, test_1) {
  try {
    s21::vector<int> vector;
    vector.clear();
  } catch (...) {
    EXPECT_FALSE(true);
  }
}
