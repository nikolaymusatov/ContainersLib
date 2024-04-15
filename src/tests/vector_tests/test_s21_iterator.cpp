#include "test_s21_main.h"

TEST(begin_function, test_0) {
  try {
    s21::vector<int> vector({4, 5});
    EXPECT_EQ(*vector.begin(), 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(end_function, test_0) {
  try {
    s21::vector<int> vector({4, 5});
    EXPECT_EQ(*(--vector.end()), 5);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_reassignment_test, test_0) {
  try {
    s21::vector<int> vector({4, 5});
    s21::vector<int> vector1({1, 2, 3});
    s21::vector<int>::iterator itr = vector.begin();
    s21::vector<int>::iterator itr1 = vector1.begin();
    itr1 = itr;
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_reassignment_test, test_1) {
  try {
    s21::vector<int> vector({4, 5});
    s21::vector<int> vector1({1, 2, 3});
    s21::vector<int>::iterator itr = vector.begin();
    s21::vector<int>::const_iterator itr1 = itr;
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_reassignment_test, test_2) {
  try {
    s21::vector<int> vector({4, 5});
    s21::vector<int> vector1({1, 2, 3});
    s21::vector<int>::iterator itr(vector.begin());
    s21::vector<int>::const_iterator itr1 = itr;
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_access_operator, test_0) {
  try {
    s21::vector<int> vector({1, 2});
    s21::vector<int>::iterator itr(vector.begin());
    ASSERT_EQ(vector.at(0), *itr);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_access_operator, test_1) {
  try {
    s21::vector<int> vector(1);
    s21::vector<int>::iterator itr(vector.begin());
    *itr = 4;
    ASSERT_EQ(*itr, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_access_operator, test_2) {
  try {
    s21::vector<int> vector(4);
    s21::vector<int>::iterator itr(vector.begin() + 1);
    *itr = 4;
    ASSERT_EQ(*itr, vector.at(1));
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_increment, test_0) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::iterator itr(vector.begin());
    for (int i = 0; itr != vector.end(); ++itr, ++i) {
      ASSERT_EQ(vector.at(i), *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_decrement, test_0) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::iterator itr(--vector.end());
    for (int i = 4; itr != --vector.begin(); --itr, --i) {
      ASSERT_EQ(vector.at(i), *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_equals, test_0) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::iterator itr(vector.begin());
    s21::vector<int>::iterator itr1(vector.begin());
    ASSERT_TRUE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_equals, test_1) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::iterator itr(vector.begin());
    s21::vector<int>::iterator itr1(vector.begin());
    ++itr1;
    ASSERT_FALSE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_not_equals, test_0) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::iterator itr(vector.begin());
    s21::vector<int>::iterator itr1(vector.begin());
    ASSERT_FALSE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_not_equals, test_1) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::iterator itr(vector.begin());
    s21::vector<int>::iterator itr1(vector.begin());
    ++itr1;
    ASSERT_TRUE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}