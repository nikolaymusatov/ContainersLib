#include "test_s21_main.h"

TEST(push_back_function, test_0) {
  s21::vector<int> vector;
  EXPECT_NO_THROW(vector.push_back(1));
  EXPECT_NO_THROW(vector.push_back(2));
  ASSERT_EQ(vector.at(0), 1);
  ASSERT_EQ(vector.at(1), 2);
  ASSERT_EQ(vector.size(), 2);
  ASSERT_EQ(vector.capacity(), 2);
}

TEST(push_back_function, test_1) {
  s21::vector<double> vector;
  double value = 3.4;
  EXPECT_NO_THROW(vector.push_back(value));
  EXPECT_NO_THROW(vector.push_back(value));
  ASSERT_EQ(vector.at(0), value);
  ASSERT_EQ(vector.at(1), value);
  ASSERT_EQ(vector.size(), 2);
  ASSERT_EQ(vector.capacity(), 2);
}
