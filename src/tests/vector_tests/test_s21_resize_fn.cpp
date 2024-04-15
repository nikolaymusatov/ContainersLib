#include "test_s21_main.h"

TEST(resize_function, test_0) {
  s21::vector<int> vector;
  EXPECT_NO_THROW(vector.resize(10));
  ASSERT_EQ(vector.size(), 10);
  ASSERT_EQ(vector.capacity(), 10);
}

TEST(resize_function, test_2) {
  s21::vector<double> vector;
  EXPECT_NO_THROW(vector.push_back(3.4));
  EXPECT_NO_THROW(vector.push_back(3.5));
  EXPECT_NO_THROW(vector.resize(30));
  EXPECT_EQ(vector.size(), 30);
  EXPECT_EQ(vector.capacity(), 30);
  EXPECT_EQ(vector.at(0), 3.4);
  EXPECT_EQ(vector.at(1), 3.5);
}

TEST(resize_function, test_3) {
  s21::vector<double> vector;
  EXPECT_NO_THROW(vector.resize(4));
  EXPECT_NO_THROW(vector.push_back(3.4));
  EXPECT_NO_THROW(vector.push_back(3.5));
  EXPECT_EQ(vector.size(), 6);
  EXPECT_EQ(vector.capacity(), 8);
  EXPECT_EQ(vector.at(4), 3.4);
  EXPECT_EQ(vector.at(5), 3.5);
}
