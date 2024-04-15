#include "test_s21_main.h"

TEST(const_iterator_reassignment_test, test_0) {
  try {
    s21::vector<int> vector({4, 5});
    s21::vector<int> vector1({1, 2, 3});
    s21::vector<int>::const_iterator itr = vector.begin();
    s21::vector<int>::const_iterator itr1 = vector1.begin();
    itr = itr1;
    EXPECT_EQ(*itr1, 1);
    EXPECT_EQ(*itr, 1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_reassignment_test, test_1) {
  try {
    s21::vector<int> vector({4, 5});
    s21::vector<int> vector1({1, 2, 3});
    s21::vector<int>::iterator itr = vector.begin();
    s21::vector<int>::const_iterator itr1 = vector1.begin();
    itr1 = itr;
    EXPECT_EQ(*itr1, 4);
    EXPECT_EQ(*itr, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_reassignment_test, test_2) {
  try {
    s21::vector<int> vector({4, 5});
    s21::vector<int> vector1({1, 2, 3});
    s21::vector<int>::iterator itr = vector.begin();
    s21::vector<int>::const_iterator itr1 = itr;
    EXPECT_EQ(*itr, 4);
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_reassignment_test, test_3) {
  try {
    const s21::vector<int> vector({4, 5});
    s21::vector<int> vector1({1, 2, 3});
    s21::vector<int>::const_iterator itr = vector.begin();
    s21::vector<int>::const_iterator itr1 = itr;
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_reassignment_test, test_4) {
  try {
    const s21::vector<int> vector({4, 5});
    s21::vector<int> vector1({1, 2, 3});
    s21::vector<int>::const_iterator itr = vector.begin();
    s21::vector<int>::const_iterator itr1(itr);
    EXPECT_EQ(*itr1, 4);
    EXPECT_EQ(*itr, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_access_operator, test_0) {
  try {
    const s21::vector<int> vector({1, 2});
    s21::vector<int>::const_iterator itr(vector.begin());
    ASSERT_EQ(*itr, 1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_access_operator, test_1) {
  try {
    const s21::vector<int> vector({1, 2, 3, 4});
    s21::vector<int>::const_iterator itr(vector.begin());
    ASSERT_EQ(*itr, 1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_increment, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const s21::vector<int> vector(init_list);
    s21::vector<int>::const_iterator itr(vector.begin());
    for (int i = 0; itr != vector.end(); ++itr, ++i) {
      ASSERT_EQ(init_list.begin()[i], *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_decrement, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const s21::vector<int> vector(init_list);
    s21::vector<int>::const_iterator itr(--vector.end());
    for (int i = 4; itr != --vector.begin(); --itr, --i) {
      ASSERT_EQ(init_list.begin()[i], *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_equals, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const s21::vector<int> vector(init_list);
    s21::vector<int>::const_iterator itr(vector.begin());
    s21::vector<int>::const_iterator itr1(vector.begin());
    ASSERT_TRUE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_equals, test_1) {
  try {
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const s21::vector<int> vector(init_list);
    s21::vector<int>::const_iterator itr(vector.begin());
    s21::vector<int>::const_iterator itr1(vector.begin());
    ++itr1;
    ASSERT_FALSE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_not_equals, test_0) {
  try {
    const s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::const_iterator itr(vector.begin());
    s21::vector<int>::const_iterator itr1(vector.begin());
    ASSERT_FALSE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_not_equals, test_1) {
  try {
    const s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::const_iterator itr(vector.begin());
    s21::vector<int>::const_iterator itr1(vector.begin());
    ++itr1;
    ASSERT_TRUE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_access_operator, test_0) {
  try {
    s21::vector<int> vector({1, 2});
    s21::vector<int>::const_iterator itr(vector.begin());
    ASSERT_EQ(vector.at(0), *itr);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_access_operator, test_1) {
  try {
    s21::vector<int> vector({1, 2, 3, 4});
    s21::vector<int>::const_iterator itr(vector.begin());
    ASSERT_EQ(*itr, 1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_increment, test_0) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::const_iterator itr(vector.begin());
    for (int i = 0; itr != vector.end(); ++itr, ++i) {
      ASSERT_EQ(vector.at(i), *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_decrement, test_0) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::const_iterator itr(--vector.end());
    for (int i = 4; itr != --vector.begin(); --itr, --i) {
      ASSERT_EQ(vector.at(i), *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_equals, test_0) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::const_iterator itr(vector.begin());
    s21::vector<int>::const_iterator itr1(vector.begin());
    ASSERT_TRUE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_equals, test_1) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::const_iterator itr(vector.begin());
    s21::vector<int>::const_iterator itr1(vector.begin());
    ++itr1;
    ASSERT_FALSE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_not_equals, test_0) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::const_iterator itr(vector.begin());
    s21::vector<int>::const_iterator itr1(vector.begin());
    ASSERT_FALSE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_not_equals, test_1) {
  try {
    s21::vector<int> vector({1, 2, 3, 4, 5});
    s21::vector<int>::const_iterator itr(vector.begin());
    s21::vector<int>::const_iterator itr1(vector.begin());
    ++itr1;
    ASSERT_TRUE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}