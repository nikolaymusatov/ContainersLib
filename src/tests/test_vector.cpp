#include <limits>

#include "test.h"

using namespace MyNamespace;

TEST(at_acces_function, test_0) {
  const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
  Vector<int> vector(init_list);
  ASSERT_EQ(vector.at(0), 1);
}

TEST(at_acces_function, test_1) {
  const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
  Vector<int> vector(init_list);
  try {
    vector.at(10);
  } catch (const std::out_of_range &e) {
    EXPECT_STREQ(e.what(),
                 "Requested element: 10 is outside the allowed vector size: 5");
  }
}

TEST(at_acces_function, test_2) {
  const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
  Vector<int> vector(init_list);
  try {
    vector.at(-2);
  } catch (const std::out_of_range &e) {
    EXPECT_EQ(e.what(),
              "Requested element: " + std::to_string(static_cast<size_t>(-2)) +
                  " is outside the allowed vector size: 5");
  }
}

TEST(back_access_function, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    Vector<int> vector(init_list);
    ASSERT_EQ(vector.back(), 1233);
    ASSERT_EQ(vector.size(), 3);
    ASSERT_EQ(vector.capacity(), 3);
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(back_access_function, test_1) {
  try {
    std::initializer_list<int> init_list = {1};
    Vector<int> vector(init_list);
    ASSERT_EQ(vector.back(), 1);
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(clear_function, test_0) {
  try {
    Vector<int> vector(4);
    vector.clear();
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(clear_function, test_1) {
  try {
    Vector<int> vector;
    vector.clear();
  } catch (...) {
    EXPECT_FALSE(true);
  }
}
TEST(const_iterator_reassignment_test, test_0) {
  try {
    Vector<int> vector({4, 5});
    Vector<int> vector1({1, 2, 3});
    Vector<int>::const_iterator itr = vector.begin();
    Vector<int>::const_iterator itr1 = vector1.begin();
    itr = itr1;
    EXPECT_EQ(*itr1, 1);
    EXPECT_EQ(*itr, 1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_reassignment_test, test_1) {
  try {
    Vector<int> vector({4, 5});
    Vector<int> vector1({1, 2, 3});
    Vector<int>::iterator itr = vector.begin();
    Vector<int>::const_iterator itr1 = vector1.begin();
    itr1 = itr;
    EXPECT_EQ(*itr1, 4);
    EXPECT_EQ(*itr, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_reassignment_test, test_2) {
  try {
    Vector<int> vector({4, 5});
    Vector<int> vector1({1, 2, 3});
    Vector<int>::iterator itr = vector.begin();
    Vector<int>::const_iterator itr1 = itr;
    EXPECT_EQ(*itr, 4);
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_reassignment_test, test_3) {
  try {
    const Vector<int> vector({4, 5});
    Vector<int> vector1({1, 2, 3});
    Vector<int>::const_iterator itr = vector.begin();
    Vector<int>::const_iterator itr1 = itr;
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_reassignment_test, test_4) {
  try {
    const Vector<int> vector({4, 5});
    Vector<int> vector1({1, 2, 3});
    Vector<int>::const_iterator itr = vector.begin();
    Vector<int>::const_iterator itr1(itr);
    EXPECT_EQ(*itr1, 4);
    EXPECT_EQ(*itr, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_access_operator, test_0) {
  try {
    const Vector<int> vector({1, 2});
    Vector<int>::const_iterator itr(vector.begin());
    ASSERT_EQ(*itr, 1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_access_operator, test_1) {
  try {
    const Vector<int> vector({1, 2, 3, 4});
    Vector<int>::const_iterator itr(vector.begin());
    ASSERT_EQ(*itr, 1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_increment, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const Vector<int> vector(init_list);
    Vector<int>::const_iterator itr(vector.begin());
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
    const Vector<int> vector(init_list);
    Vector<int>::const_iterator itr(--vector.end());
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
    const Vector<int> vector(init_list);
    Vector<int>::const_iterator itr(vector.begin());
    Vector<int>::const_iterator itr1(vector.begin());
    ASSERT_TRUE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_equals, test_1) {
  try {
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const Vector<int> vector(init_list);
    Vector<int>::const_iterator itr(vector.begin());
    Vector<int>::const_iterator itr1(vector.begin());
    ++itr1;
    ASSERT_FALSE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_not_equals, test_0) {
  try {
    const Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::const_iterator itr(vector.begin());
    Vector<int>::const_iterator itr1(vector.begin());
    ASSERT_FALSE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_vector_const_iterator_not_equals, test_1) {
  try {
    const Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::const_iterator itr(vector.begin());
    Vector<int>::const_iterator itr1(vector.begin());
    ++itr1;
    ASSERT_TRUE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_access_operator, test_0) {
  try {
    Vector<int> vector({1, 2});
    Vector<int>::const_iterator itr(vector.begin());
    ASSERT_EQ(vector.at(0), *itr);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_access_operator, test_1) {
  try {
    Vector<int> vector({1, 2, 3, 4});
    Vector<int>::const_iterator itr(vector.begin());
    ASSERT_EQ(*itr, 1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_increment, test_0) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::const_iterator itr(vector.begin());
    for (int i = 0; itr != vector.end(); ++itr, ++i) {
      ASSERT_EQ(vector.at(i), *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_decrement, test_0) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::const_iterator itr(--vector.end());
    for (int i = 4; itr != --vector.begin(); --itr, --i) {
      ASSERT_EQ(vector.at(i), *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_equals, test_0) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::const_iterator itr(vector.begin());
    Vector<int>::const_iterator itr1(vector.begin());
    ASSERT_TRUE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_equals, test_1) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::const_iterator itr(vector.begin());
    Vector<int>::const_iterator itr1(vector.begin());
    ++itr1;
    ASSERT_FALSE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_not_equals, test_0) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::const_iterator itr(vector.begin());
    Vector<int>::const_iterator itr1(vector.begin());
    ASSERT_FALSE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(const_iterator_not_equals, test_1) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::const_iterator itr(vector.begin());
    Vector<int>::const_iterator itr1(vector.begin());
    ++itr1;
    ASSERT_TRUE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}
TEST(constructor_with_size, test_0) {
  try {
    Vector<double> vector(10);
    ASSERT_EQ(vector.size(), 10);
    ASSERT_EQ(vector.capacity(), 10);
  } catch (const std::bad_alloc &e) {
    ASSERT_TRUE(false);
  }
}

TEST(constructor_with_size, test_1) {
  try {
    Vector<double> vector(0);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
  } catch (const std::bad_alloc &e) {
    ASSERT_TRUE(false);
  }
}

TEST(constructor_with_initilized_list, test_0) {
  const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
  Vector<int> vector(init_list);
  ASSERT_EQ(vector.size(), 5);
  ASSERT_EQ(vector.capacity(), 5);
}

TEST(copy_constructor, test_0) {
  const std::initializer_list<double> init_list = {1, 2, 3, 4, 5};
  try {
    Vector<double> vector(init_list);
    Vector<double> copy_vector(vector);
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 5);
    ASSERT_EQ(copy_vector.size(), 5);
    ASSERT_EQ(copy_vector.capacity(), 5);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list.begin()[i]);
      ASSERT_EQ(copy_vector.at(i), init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(move_constructor, test_0) {
  const std::initializer_list<double> init_list = {1, 2, 3, 4, 5};
  try {
    std::vector<double> vector(init_list);
    std::vector<double> dest_vector(std::move(vector));
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    ASSERT_EQ(dest_vector.size(), 5);
    ASSERT_EQ(dest_vector.capacity(), 5);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(dest_vector.at(i), init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(access_data_fn, test_0) {
  Vector<double> vector(10);
  vector.push_back(14);
  ASSERT_EQ(vector.size(), 11);
  ASSERT_EQ(vector.capacity(), 20);
  ASSERT_EQ(*(vector.data() + 10), 14);
}

TEST(access_data_fn, test_1) {
  Vector<double> vector;
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

TEST(empty_function, test_0) {
  Vector<int> vector;
  EXPECT_TRUE(vector.empty());
}

TEST(empty_function, test_1) {
  Vector<int> vector(10);
  EXPECT_FALSE(vector.empty());
}

TEST(erase_function, test_0) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    Vector<int> vector(init_list);
    vector.erase(vector.begin() + 2);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 5);
    ASSERT_EQ(vector.at(2), 4);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(erase_function, test_1) {
  try {
    const std::initializer_list<int> init_list = {1};
    Vector<int> vector(init_list);
    vector.erase(vector.begin());
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 1);
    ASSERT_EQ(vector[0], 1);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(erase_function, test_2) {
  try {
    Vector<int> vector;
    vector.erase(vector.begin());
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(front_access_function, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    Vector<int> vector(init_list);
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
    Vector<int> vector(init_list);
    ASSERT_EQ(vector.front(), 1);
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(insert_function, test_0) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const std::initializer_list<int> init_list_1 = {21, 1, 2, 3, 4, 5};
    Vector<int> vector(init_list);
    Vector<int>::iterator itr = vector.begin();
    Vector<int>::iterator itr1 = vector.insert(itr, 21);
    ASSERT_EQ(*itr1, 21);
    ASSERT_EQ(vector.size(), 6);
    ASSERT_EQ(vector.capacity(), 10);
    for (int i = 0; i < init_list_1.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list_1.begin()[i]);
    }
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(insert_function, test_1) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const std::initializer_list<int> init_list_1 = {1, 2, 3, 21, 4, 5};
    Vector<int> vector(init_list);
    Vector<int>::iterator itr = vector.begin() + 3;
    Vector<int>::iterator itr1 = vector.insert(itr, 21);
    ASSERT_EQ(*itr1, 21);
    ASSERT_EQ(vector.size(), 6);
    ASSERT_EQ(vector.capacity(), 10);
    for (int i = 0; i < init_list_1.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list_1.begin()[i]);
    }
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(insert_function, test_2) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const std::initializer_list<int> init_list_1 = {1, 2, 3, 4, 5, 21};
    Vector<int> vector(init_list);
    Vector<int>::iterator itr = vector.begin() + 5;
    Vector<int>::iterator itr1 = vector.insert(itr, 21);
    ASSERT_EQ(*itr1, 21);
    ASSERT_EQ(vector.size(), 6);
    ASSERT_EQ(vector.capacity(), 10);
    for (int i = 0; i < init_list_1.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list_1.begin()[i]);
    }
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(insert_function, test_3) {
  try {
    Vector<int> vector;
    Vector<int>::iterator itr = vector.begin();
    Vector<int>::iterator itr1 = vector.insert(itr, 21);
    ASSERT_EQ(*itr1, 21);
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
    ASSERT_EQ(vector.at(0), 21);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}
TEST(interaction_with_objects, test_0) {
  try {
    std::initializer_list<int> list = {1, 2, 3, 4, 5};
    Vector<int> v(list);
    Vector<Vector<int>> vector;
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    vector.push_back(v);
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
    for (int i = 0; i < list.size(); ++i) {
      ASSERT_EQ(vector.at(0).at(i), list.begin()[i]);
    }
    for (int i = 0; i < list.size(); ++i) {
      ASSERT_EQ(v.at(i), list.begin()[i]);
    }
    ASSERT_EQ(v.size(), 5);
    ASSERT_EQ(v.capacity(), 5);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(interaction_with_objects, test_1) {
  try {
    std::initializer_list<int> list = {1, 2, 3, 4, 5};
    Vector<int> v(list);
    Vector<Vector<int>> vector;
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    vector.push_back(std::move(v));
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
    for (int i = 0; i < list.size(); ++i) {
      ASSERT_EQ(vector.at(0).at(i), list.begin()[i]);
    }
    ASSERT_EQ(v.size(), 0);
    ASSERT_EQ(v.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(begin_function, test_0) {
  try {
    Vector<int> vector({4, 5});
    EXPECT_EQ(*vector.begin(), 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(end_function, test_0) {
  try {
    Vector<int> vector({4, 5});
    EXPECT_EQ(*(--vector.end()), 5);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_reassignment_test, test_0) {
  try {
    Vector<int> vector({4, 5});
    Vector<int> vector1({1, 2, 3});
    Vector<int>::iterator itr = vector.begin();
    Vector<int>::iterator itr1 = vector1.begin();
    itr1 = itr;
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_reassignment_test, test_1) {
  try {
    Vector<int> vector({4, 5});
    Vector<int> vector1({1, 2, 3});
    Vector<int>::iterator itr = vector.begin();
    Vector<int>::const_iterator itr1 = itr;
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_reassignment_test, test_2) {
  try {
    Vector<int> vector({4, 5});
    Vector<int> vector1({1, 2, 3});
    Vector<int>::iterator itr(vector.begin());
    Vector<int>::const_iterator itr1 = itr;
    EXPECT_EQ(*itr1, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_access_operator, test_0) {
  try {
    Vector<int> vector({1, 2});
    Vector<int>::iterator itr(vector.begin());
    ASSERT_EQ(vector.at(0), *itr);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_access_operator, test_1) {
  try {
    Vector<int> vector(1);
    Vector<int>::iterator itr(vector.begin());
    *itr = 4;
    ASSERT_EQ(*itr, 4);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_access_operator, test_2) {
  try {
    Vector<int> vector(4);
    Vector<int>::iterator itr(vector.begin() + 1);
    *itr = 4;
    ASSERT_EQ(*itr, vector.at(1));
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_increment, test_0) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::iterator itr(vector.begin());
    for (int i = 0; itr != vector.end(); ++itr, ++i) {
      ASSERT_EQ(vector.at(i), *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_decrement, test_0) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::iterator itr(--vector.end());
    for (int i = 4; itr != --vector.begin(); --itr, --i) {
      ASSERT_EQ(vector.at(i), *itr);
    }
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_equals, test_0) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::iterator itr(vector.begin());
    Vector<int>::iterator itr1(vector.begin());
    ASSERT_TRUE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_equals, test_1) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::iterator itr(vector.begin());
    Vector<int>::iterator itr1(vector.begin());
    ++itr1;
    ASSERT_FALSE(itr == itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_not_equals, test_0) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::iterator itr(vector.begin());
    Vector<int>::iterator itr1(vector.begin());
    ASSERT_FALSE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(iterator_not_equals, test_1) {
  try {
    Vector<int> vector({1, 2, 3, 4, 5});
    Vector<int>::iterator itr(vector.begin());
    Vector<int>::iterator itr1(vector.begin());
    ++itr1;
    ASSERT_TRUE(itr != itr1);
  } catch (...) {
    EXPECT_TRUE(false);
  }
}

TEST(max_size_function, test_0) {
  Vector<int> vector;
  ASSERT_EQ(vector.max_size(),
            std::numeric_limits<size_t>::max() / sizeof(int));
}

TEST(max_size_function, test_1) {
  Vector<std::string> vector;
  ASSERT_EQ(vector.max_size(),
            std::numeric_limits<size_t>::max() / sizeof(std::string));
}

TEST(assignment_operator, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    Vector<int> vector(init_list);
    Vector<int> new_vector = std::move(vector);
    ASSERT_EQ(new_vector.size(), 3);
    ASSERT_EQ(new_vector.capacity(), 3);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(new_vector.at(i), init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(assignment_operator, test_1) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    Vector<int> vector(init_list);
    Vector<int> new_vector(4);
    new_vector = std::move(vector);
    ASSERT_EQ(new_vector.size(), 3);
    ASSERT_EQ(new_vector.capacity(), 3);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(new_vector.at(i), init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(assignment_operator, test_2) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    Vector<int> vector(init_list);
    vector = std::move(vector);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(assignment_operator_not_bouds_checking, test_0) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    Vector<int> vector(init_list);
    for (int i = 0; i < init_list.size(); ++i) {
      ASSERT_EQ(vector[i], init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(assignment_operator_not_bouds_checking, test_1) {
  try {
    std::initializer_list<int> init_list = {1, 16435, 1233};
    Vector<int> vector(3);
    for (int i = 0; i < init_list.size(); ++i) {
      vector[i] = init_list.begin()[i];
      ASSERT_EQ(vector[i], init_list.begin()[i]);
    }
  } catch (...) {
    ASSERT_TRUE(false);
  }
}

TEST(pop_back_function, test_0) {
  try {
    Vector<int> vector({1, 2, 3, 4});
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 4);
    vector.push_back(21);
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 8);
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    ASSERT_EQ(vector.size(), 2);
    ASSERT_EQ(vector.capacity(), 8);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(pop_back_function, test_1) {
  try {
    Vector<Vector<int>> vector(4);
    Vector<int> tmp_vector({1, 2, 3, 4});
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 4);
    vector.push_back(tmp_vector);
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 8);
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    ASSERT_EQ(vector.size(), 2);
    ASSERT_EQ(vector.capacity(), 8);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(pop_back_function, test_2) {
  try {
    Vector<int> vector;
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    vector.pop_back();
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(push_back_function, test_0) {
  Vector<int> vector;
  EXPECT_NO_THROW(vector.push_back(1));
  EXPECT_NO_THROW(vector.push_back(2));
  ASSERT_EQ(vector.at(0), 1);
  ASSERT_EQ(vector.at(1), 2);
  ASSERT_EQ(vector.size(), 2);
  ASSERT_EQ(vector.capacity(), 2);
}

TEST(push_back_function, test_1) {
  Vector<double> vector;
  double value = 3.4;
  EXPECT_NO_THROW(vector.push_back(value));
  EXPECT_NO_THROW(vector.push_back(value));
  ASSERT_EQ(vector.at(0), value);
  ASSERT_EQ(vector.at(1), value);
  ASSERT_EQ(vector.size(), 2);
  ASSERT_EQ(vector.capacity(), 2);
}

TEST(test_reserve_function, test_0) {
  try {
    Vector<std::string> vector(4);
    vector.push_back("a");
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 8);
    vector.reserve(100);
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector.capacity(), 100);
    vector.push_back("b");
    ASSERT_EQ(vector.size(), 6);
    ASSERT_EQ(vector.capacity(), 100);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(test_reserve_function, test_1) {
  try {
    Vector<std::string> vector(4);
    vector.reserve(100);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 100);
    vector.reserve(50);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 100);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(test_reserve_function, test_2) {
  try {
    Vector<std::string> vector(4);
    vector.reserve(0);
    ASSERT_EQ(vector.size(), 4);
    ASSERT_EQ(vector.capacity(), 4);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(test_reserve_function, test_3) {
  try {
    Vector<std::string> vector(4);
    EXPECT_THROW(vector.reserve(-1), std::length_error);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(resize_function, test_0) {
  Vector<int> vector;
  EXPECT_NO_THROW(vector.resize(10));
  ASSERT_EQ(vector.size(), 10);
  ASSERT_EQ(vector.capacity(), 10);
}

TEST(resize_function, test_2) {
  Vector<double> vector;
  EXPECT_NO_THROW(vector.push_back(3.4));
  EXPECT_NO_THROW(vector.push_back(3.5));
  EXPECT_NO_THROW(vector.resize(30));
  EXPECT_EQ(vector.size(), 30);
  EXPECT_EQ(vector.capacity(), 30);
  EXPECT_EQ(vector.at(0), 3.4);
  EXPECT_EQ(vector.at(1), 3.5);
}

TEST(resize_function, test_3) {
  Vector<double> vector;
  EXPECT_NO_THROW(vector.resize(4));
  EXPECT_NO_THROW(vector.push_back(3.4));
  EXPECT_NO_THROW(vector.push_back(3.5));
  EXPECT_EQ(vector.size(), 6);
  EXPECT_EQ(vector.capacity(), 8);
  EXPECT_EQ(vector.at(4), 3.4);
  EXPECT_EQ(vector.at(5), 3.5);
}

TEST(shrink_to_fit_function, test_0) {
  try {
    Vector<std::string> vector(4);
    vector.push_back("a");
    ASSERT_EQ(vector.capacity(), 8);
    vector.shrink_to_fit();
    ASSERT_EQ(vector.capacity(), 5);
    vector.push_back("b");
    ASSERT_EQ(vector.capacity(), 10);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(shrink_to_fit_function, test_1) {
  try {
    Vector<std::string> vector;
    ASSERT_EQ(vector.capacity(), 0);
    vector.shrink_to_fit();
    ASSERT_EQ(vector.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(shrink_to_fit_function, test_2) {
  try {
    Vector<std::string> vector(4);
    vector.push_back("a");
    vector.shrink_to_fit();
    ASSERT_EQ(vector.capacity(), 5);
    vector.push_back("b");
    ASSERT_EQ(vector.capacity(), 10);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(constructor_with_size__stress, test_0) {
  try {
    Vector<double> vector(100000000000000);
  } catch (const std::bad_alloc &e) {
    ASSERT_TRUE(true);
  }
}

TEST(resize_function__stress, test_0) {
  Vector<int> vector;
  EXPECT_THROW(vector.resize(-1), std::length_error);
  EXPECT_EQ(vector.size(), 0);
  EXPECT_EQ(vector.capacity(), 0);
}

TEST(resize_function__stress, test_1) {
  Vector<double> vector;
  EXPECT_THROW(vector.resize(100000000000000), std::bad_alloc);
  EXPECT_EQ(vector.size(), 0);
  EXPECT_EQ(vector.capacity(), 0);
}

TEST(push_back_function__stress, test_0) {
  Vector<double> vector;
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

TEST(swap_function, test_0) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    Vector<int> vector(init_list);
    Vector<int> vector1(init_list);
    vector.swap(vector1);
    for (int i = 0; i < vector.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list.begin()[i]);
    }
    for (int i = 0; i < vector1.size(); ++i) {
      ASSERT_EQ(vector1.at(i), init_list.begin()[i]);
    }
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector1.size(), 5);
    ASSERT_EQ(vector.capacity(), 5);
    ASSERT_EQ(vector1.capacity(), 5);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(swap_function, test_1) {
  try {
    const std::initializer_list<int> init_list = {1};
    Vector<int> vector(init_list);
    Vector<int> vector1(init_list);
    vector.swap(vector1);
    for (int i = 0; i < vector.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list.begin()[i]);
    }
    for (int i = 0; i < vector1.size(); ++i) {
      ASSERT_EQ(vector1.at(i), init_list.begin()[i]);
    }
    ASSERT_EQ(vector.size(), 1);
    ASSERT_EQ(vector1.size(), 1);
    ASSERT_EQ(vector.capacity(), 1);
    ASSERT_EQ(vector1.capacity(), 1);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(swap_function, test_3) {
  try {
    const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    const std::initializer_list<int> init_list1 = {1};
    Vector<int> vector(init_list1);
    Vector<int> vector1(init_list);
    vector.swap(vector1);
    for (int i = 0; i < vector.size(); ++i) {
      ASSERT_EQ(vector.at(i), init_list.begin()[i]);
    }
    for (int i = 0; i < vector1.size(); ++i) {
      ASSERT_EQ(vector1.at(i), init_list1.begin()[i]);
    }
    ASSERT_EQ(vector.size(), 5);
    ASSERT_EQ(vector1.size(), 1);
    ASSERT_EQ(vector.capacity(), 5);
    ASSERT_EQ(vector1.capacity(), 1);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}

TEST(swap_function, test_4) {
  try {
    Vector<int> vector;
    Vector<int> vector1;
    vector.swap(vector1);
    ASSERT_EQ(vector.size(), 0);
    ASSERT_EQ(vector1.size(), 0);
    ASSERT_EQ(vector.capacity(), 0);
    ASSERT_EQ(vector1.capacity(), 0);
  } catch (...) {
    EXPECT_FALSE(true);
  }
}