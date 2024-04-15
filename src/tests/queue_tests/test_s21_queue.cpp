#include "test_s21_main.h"

using namespace s21;
#include <queue>

void compare_queues(queue<int> &s21_q, std::queue<int> &std_q) {
  while (s21_q.size() || std_q.size()) {
    ASSERT_EQ(s21_q.front(), std_q.front());
    ASSERT_EQ(s21_q.back(), std_q.back());
    s21_q.pop();
    std_q.pop();
  }
}

TEST(Queue_Front, Test_1) {
  queue<int> q;
  q.push(1);
  q.push(2);
  ASSERT_TRUE(q.front() == 1);
}

TEST(Queue_Front, Test_2) {
  queue<std::string> q;
  q.push("test");
  ASSERT_TRUE(q.front() == "test");
}

TEST(Queue_Front, Test_3) {
  queue<double> q;
  q.push(0.5);
  ASSERT_TRUE(q.front() == 0.5);
}

TEST(Queue_Back, Test_1) {
  queue<int> q;
  q.push(1);
  q.push(2);
  ASSERT_TRUE(q.back() == 2);
}

TEST(Queue_Back, Test_2) {
  queue<std::string> q;
  q.push("test");
  ASSERT_TRUE(q.back() == "test");
}

TEST(Queue_Back, Test_3) {
  queue<double> q;
  q.push(0.5);
  ASSERT_TRUE(q.back() == 0.5);
}

TEST(Queue_Size, Test_1) {
  queue<std::string> q;
  ASSERT_TRUE(q.size() == 0);
}

TEST(Queue_Size, Test_2) {
  queue<int> q{1, 2, 3, 4, 5};
  ASSERT_TRUE(q.size() == 5);
}

TEST(Queue_Size, Test_3) {
  queue<char> q{'a', 'b', 'c', 'd'};
  ASSERT_TRUE(q.size() == 4);
}

TEST(Queue_Empty, Test_1) {
  queue<int> q{1, 2, 3, 4, 5};
  ASSERT_TRUE(!q.empty());
}

TEST(Queue_Empty, Test_2) {
  queue<int> q;
  ASSERT_TRUE(q.empty());
}

TEST(Queue_Empty, Test_3) {
  queue<int> q{1, 2, 3};
  queue<int> q2(q);
  for (int i = 0; i < 3; i++) q2.pop();
  ASSERT_TRUE(q2.empty());
}

TEST(Queue_Swap, Test_1) {
  queue<int> q{1, 2, 3};
  queue<int> q2;
  q2.swap(q);
  ASSERT_TRUE(q.empty());
  ASSERT_TRUE(q2.front() == 1);
  ASSERT_TRUE(q2.size() == 3);
}

TEST(Queue_Swap, Test_2) {
  queue<char> q{'1', '2', '3'};
  queue<char> q2{'7', '8'};
  q2.swap(q);
  ASSERT_TRUE(q2.front() == '1');
  ASSERT_TRUE(q2.size() == 3);
  ASSERT_TRUE(q.front() == '7');
  ASSERT_TRUE(q.size() == 2);
}

TEST(Queue_MoveConstructor, Test_1) {
  queue<int> q{1, 2, 3};
  queue<int> q2{std::move(q)};
  ASSERT_TRUE(q.empty());
  ASSERT_TRUE(!q2.empty());
  ASSERT_TRUE(q2.size() == 3);
}

TEST(Queue_Copy_Operator, Test_1) {
  queue<int> s21_queue;
  queue<int> s21_queue_copy{1, 2, 3};
  std::initializer_list<int> data{1, 2, 3};
  std::queue<int> std_queue(data);

  s21_queue = s21_queue_copy;
  compare_queues(s21_queue, std_queue);
}

TEST(Queue_Move_Operator, Test_1) {
  queue<int> s21_queue;
  queue<int> s21_queue_copy{1, 2, 3};
  std::initializer_list<int> data{1, 2, 3};
  std::queue<int> std_queue(data);

  s21_queue = std::move(s21_queue_copy);
  compare_queues(s21_queue, std_queue);
}
