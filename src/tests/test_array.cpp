#include "test.h"

using namespace MyNamespace;

TEST(Array_At, Test_1) {
  Array<int, 3> a{1, 2, 3};
  ASSERT_TRUE(a.at(0) == 1);
}

TEST(Array_At, Test_2) {
  Array<int, 3> a{1, 2, 3};
  try {
    a.at(5);
  } catch (const char *e) {
    ASSERT_TRUE(true);
  }
}

TEST(Array_Operator, Test_1) {
  Array<int, 3> a{1, 2, 3};
  ASSERT_TRUE(a[0] == 1);
  ASSERT_TRUE(a[1] == 2);
  ASSERT_TRUE(a[2] == 3);
}

TEST(Array_Begin_End, Test_1) {
  Array<std::string, 3> a{"carisafi", "peachgha", "greapfru"};
  ASSERT_TRUE(*a.begin() == "carisafi");
  ASSERT_TRUE(*(a.end() - 1) == "greapfru");
}

TEST(Array_Empty, Test_1) {
  Array<int, 3> a{1, 2, 3};
  ASSERT_FALSE(a.empty());
}

TEST(Array_Empty, Test_2) {
  Array<int, 0> a;
  ASSERT_TRUE(a.empty());
}

TEST(Array_Size, Test_1) {
  Array<int, 3> a{1, 2, 3};
  ASSERT_TRUE(a.size() == 3);
}

TEST(Array_Size, Test_2) {
  Array<int, 3> a;
  ASSERT_TRUE(a.size() == 3);
}

TEST(Array_Size, Test_3) {
  Array<int, 0> a;
  ASSERT_TRUE(a.size() == 0);
}

TEST(Array_Sizemax, Test_1) {
  Array<int, 3> a{1, 2, 3};
  ASSERT_TRUE(a.max_size() == 3);
}

TEST(Array_Fill, Test_1) {
  Array<int, 3> a{1, 2, 3};
  a.fill(5);
  for (auto i = 0; i < a.size(); i++) ASSERT_TRUE(a[i] == 5);
}

TEST(Array_Swap, Test_1) {
  Array<int, 3> a{1, 2, 3}, b{4, 5, 6};
  a.swap(b);
  ASSERT_TRUE(a[0] == 4);
  ASSERT_TRUE(a[1] == 5);
  ASSERT_TRUE(a[2] == 6);
  ASSERT_TRUE(b[0] == 1);
  ASSERT_TRUE(b[1] == 2);
  ASSERT_TRUE(b[2] == 3);
}

TEST(Array_Front, Test_1) {
  Array<int, 3> a{1, 2, 3};
  auto pos = a.front();
  ASSERT_TRUE(pos == 1);
}

TEST(Array_Back, Test_1) {
  Array<int, 3> a{1, 2, 3};
  auto pos = a.back();
  ASSERT_TRUE(pos == 3);
}

TEST(Array_Data, Test_1) {
  Array<int, 3> a{1, 2, 3};
  auto pos = a.data();
  ASSERT_EQ(pos, &a[0]);
}