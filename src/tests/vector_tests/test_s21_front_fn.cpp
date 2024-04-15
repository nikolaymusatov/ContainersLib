#include "test_s21_main.h"

TEST(front_access_function, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    s21::vector<int> vector(init_list);
    ASSERT_EQ(vector.front(), 1);
    ASSERT_EQ(vector.size(), 3);
    ASSERT_EQ(vector.capacity(), 3);
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(front_access_function, test_1) {
  try {
    std::initializer_list<int> init_list = {1};
    s21::vector<int> vector(init_list);
    ASSERT_EQ(vector.front(), 1);
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
  } catch (...) {
    ASSERT_TRUE(false);
  }
}
