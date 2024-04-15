#include <queue>

#include "test.h"

using namespace MyNamespace;

void compare_queues(Queue<int> &q, std::queue<int> &std_q) {
  while (q.size() || std_q.size()) {
    ASSERT_EQ(q.front(), std_q.front());
    ASSERT_EQ(q.back(), std_q.back());
    q.pop();
    std_q.pop();
  }
}

TEST(Queue_Front, Test_1) {
  Queue<int> q;
  q.push(1);
  q.push(2);
  ASSERT_TRUE(q.front() == 1);
}

TEST(Queue_Front, Test_2) {
  Queue<std::string> q;
  q.push("test");
  ASSERT_TRUE(q.front() == "test");
}

TEST(Queue_Front, Test_3) {
  Queue<double> q;
  q.push(0.5);
  ASSERT_TRUE(q.front() == 0.5);
}

TEST(Queue_Back, Test_1) {
  Queue<int> q;
  q.push(1);
  q.push(2);
  ASSERT_TRUE(q.back() == 2);
}

TEST(Queue_Back, Test_2) {
  Queue<std::string> q;
  q.push("test");
  ASSERT_TRUE(q.back() == "test");
}

TEST(Queue_Back, Test_3) {
  Queue<double> q;
  q.push(0.5);
  ASSERT_TRUE(q.back() == 0.5);
}

TEST(Queue_Size, Test_1) {
  Queue<std::string> q;
  ASSERT_TRUE(q.size() == 0);
}

TEST(Queue_Size, Test_2) {
  Queue<int> q{1, 2, 3, 4, 5};
  ASSERT_TRUE(q.size() == 5);
}

TEST(Queue_Size, Test_3) {
  Queue<char> q{'a', 'b', 'c', 'd'};
  ASSERT_TRUE(q.size() == 4);
}

TEST(Queue_Empty, Test_1) {
  Queue<int> q{1, 2, 3, 4, 5};
  ASSERT_TRUE(!q.empty());
}

TEST(Queue_Empty, Test_2) {
  Queue<int> q;
  ASSERT_TRUE(q.empty());
}

TEST(Queue_Empty, Test_3) {
  Queue<int> q{1, 2, 3};
  Queue<int> q2(q);
  for (int i = 0; i < 3; i++) q2.pop();
  ASSERT_TRUE(q2.empty());
}

TEST(Queue_Swap, Test_1) {
  Queue<int> q{1, 2, 3};
  Queue<int> q2;
  q2.swap(q);
  ASSERT_TRUE(q.empty());
  ASSERT_TRUE(q2.front() == 1);
  ASSERT_TRUE(q2.size() == 3);
}

TEST(Queue_Swap, Test_2) {
  Queue<char> q{'1', '2', '3'};
  Queue<char> q2{'7', '8'};
  q2.swap(q);
  ASSERT_TRUE(q2.front() == '1');
  ASSERT_TRUE(q2.size() == 3);
  ASSERT_TRUE(q.front() == '7');
  ASSERT_TRUE(q.size() == 2);
}

TEST(Queue_MoveConstructor, Test_1) {
  Queue<int> q{1, 2, 3};
  Queue<int> q2{std::move(q)};
  ASSERT_TRUE(q.empty());
  ASSERT_TRUE(!q2.empty());
  ASSERT_TRUE(q2.size() == 3);
}

TEST(Queue_Copy_Operator, Test_1) {
  Queue<int> queue;
  Queue<int> queue_copy{1, 2, 3};
  std::initializer_list<int> data{1, 2, 3};
  std::queue<int> std_queue(data);

  queue = queue_copy;
  compare_queues(queue, std_queue);
}

TEST(Queue_Move_Operator, Test_1) {
  Queue<int> queue;
  Queue<int> queue_copy{1, 2, 3};
  std::initializer_list<int> data{1, 2, 3};
  std::queue<int> std_queue(data);

  queue = std::move(queue_copy);
  compare_queues(queue, std_queue);
}
