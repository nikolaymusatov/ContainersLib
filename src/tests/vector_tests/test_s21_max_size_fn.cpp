#include <limits>

#include "test_s21_main.h"

TEST(max_size_function, test_0) {
  s21::vector<int> vector;
  ASSERT_EQ(vector.max_size(),
            std::numeric_limits<size_t>::max() / sizeof(int));
}

TEST(max_size_function, test_1) {
  s21::vector<std::string> vector;
  ASSERT_EQ(vector.max_size(),
            std::numeric_limits<size_t>::max() / sizeof(std::string));
}
