#include "test_s21_main.h"

TEST(at_acces_function, test_0) {
  const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
  s21::vector<int> vector(init_list);
  ASSERT_EQ(vector.at(0), 1);
}

TEST(at_acces_function, test_1) {
  const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
  s21::vector<int> vector(init_list);
  try {
    vector.at(10);
  } catch (const std::out_of_range &e) {
    EXPECT_STREQ(e.what(),
                 "Requested element: 10 is outside the allowed vector size: 5");
  }
}

TEST(at_acces_function, test_2) {
  const std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
  s21::vector<int> vector(init_list);
  try {
    vector.at(-2);
  } catch (const std::out_of_range &e) {
    EXPECT_EQ(e.what(),
              "Requested element: " + std::to_string(static_cast<size_t>(-2)) +
                  " is outside the allowed vector size: 5");
  }
}
