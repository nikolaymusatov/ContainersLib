#include "test_s21_main.h"

using namespace s21;

TEST(Stack_Top, Test_1) {
  stack<int> s;
  s.push(1);
  s.push(2);
  ASSERT_TRUE(s.top() == 2);
}

TEST(Stack_Top, Test_2) {
  stack<std::string> s;
  s.push("test");
  ASSERT_TRUE(s.top() == "test");
}

TEST(Stack_Top, Test_3) {
  stack<double> s;
  s.push(0.5);
  ASSERT_TRUE(s.top() == 0.5);
}

TEST(Stack_Size, Test_1) {
  stack<std::string> s;
  ASSERT_TRUE(s.size() == 0);
}

TEST(Stack_Size, Test_2) {
  stack<int> s{1, 2, 3, 4, 5};
  ASSERT_TRUE(s.size() == 5);
}

TEST(Stack_Size, Test_3) {
  stack<char> s{'a', 'b', 'c', 'd'};
  ASSERT_TRUE(s.size() == 4);
}

TEST(Stack_Empty, Test_1) {
  stack<int> s{1, 2, 3, 4, 5};
  ASSERT_TRUE(!s.empty());
}

TEST(Stack_Empty, Test_2) {
  stack<int> s;
  ASSERT_TRUE(s.empty());
}

TEST(Stack_Empty, Test_3) {
  stack<int> s{1, 2, 3};
  stack<int> s2(s);
  for (int i = 0; i < 3; i++) s2.pop();
  ASSERT_TRUE(s2.empty());
}

TEST(Stack_Swap, Test_1) {
  stack<int> s{1, 2, 3};
  stack<int> s2;
  s2.swap(s);
  ASSERT_TRUE(s.empty());
  ASSERT_TRUE(s2.top() == 3);
  ASSERT_TRUE(s2.size() == 3);
}

TEST(Stack_Swap, Test_2) {
  stack<char> s{'1', '2', '3'};
  stack<char> s2{'7', '8'};
  s2.swap(s);
  ASSERT_TRUE(s2.top() == '3');
  ASSERT_TRUE(s2.size() == 3);
  ASSERT_TRUE(s.top() == '8');
  ASSERT_TRUE(s.size() == 2);
}

TEST(Stack_MoveConstructor, Test_1) {
  stack<int> s{1, 2, 3};
  stack<int> s2{std::move(s)};
  ASSERT_TRUE(s.empty());
  ASSERT_TRUE(!s2.empty());
  ASSERT_TRUE(s2.size() == 3);
}

TEST(Stack_MoveOperator, Test_0) {
  stack<int> s{1, 2, 3};
  stack<int> s2{4};
  s2 = std::move(s);
  ASSERT_TRUE(s.empty());
  ASSERT_TRUE(!s2.empty());
  ASSERT_TRUE(s2.size() == 3);
}

TEST(Stack_CopyOperator, Test_0) {
  std::initializer_list<int> list = {1, 2, 3};
  stack<int> s{1, 2, 3};
  stack<int> s2{4};
  s2 = s;
  ASSERT_EQ(s.size(), 3);
  ASSERT_FALSE(s.empty());
  ASSERT_EQ(s2.size(), 3);
  ASSERT_FALSE(s.empty());
  for (int j = 0; !s2.empty(); ++j) {
    ASSERT_EQ(s2.top(), list.begin()[j]);
    s2.pop();
  }
}
