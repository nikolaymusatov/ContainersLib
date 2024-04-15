#include "test_s21_main.h"

void compare_lists(s21::List<float> const &s21_list,
                   std::list<float> const &std_list) {
  auto s21_i = s21_list.begin();
  auto std_i = std_list.begin();
  while (s21_i != s21_list.end() || std_i != std_list.end()) {
    ASSERT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
}

TEST(s21_list_case, ctor_empty) {
  // default
  s21::List<float> s21_list;
  std::list<float> std_list;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(s21_list_case, ctor_parameterized) {
  // parameterized
  s21::List<float> s21_list(3);
  std::list<float> std_list(3);
  ASSERT_EQ(s21_list.size(), std_list.size());
  compare_lists(s21_list, std_list);
}

TEST(s21_list_case, ctors_size) {
  // initializer_list
  s21::List<float> s21_list{5, 4, 3, 2, 1};
  std::list<float> std_list{5, 4, 3, 2, 1};
  ASSERT_EQ(s21_list.size(), std_list.size());
  compare_lists(s21_list, std_list);

  // test for iterator loop
  auto s21_pos = s21_list.end();
  ++s21_pos;
  auto std_pos = std_list.end();
  ++std_pos;
  ASSERT_EQ(*s21_pos, *std_pos);

  // copy
  s21::List<float> s21_list_copy(s21_list);
  std::list<float> std_list_copy(std_list);
  ASSERT_EQ(s21_list_copy.size(), std_list_copy.size());
  compare_lists(s21_list_copy, std_list_copy);

  // move operator
  s21::List<float> s21_list1{1, 2, 3, 4, 5};
  s21_list1 = std::move(s21_list_copy);
  std::list<float> std_list1{5, 4, 3, 2, 1};
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  compare_lists(s21_list1, std_list1);

  // move constructor
  s21::List<float> s21_list2(std::move(s21_list1));
  std::list<float> std_list2(std::move(std_list1));
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  compare_lists(s21_list2, std_list2);
}

TEST(s21_list_case, copy_operator) {
  s21::List<float> s21_list{5};
  s21::List<float> s21_list_copy;
  std::list<float> std_list{5};

  s21_list_copy = s21_list;
  compare_lists(s21_list, std_list);
}

TEST(s21_list_case, front_back) {
  s21::List<float> s21_list{5, 4, 3, 2, 1};
  std::list<float> std_list{5, 4, 3, 2, 1};
  ASSERT_EQ(s21_list.front(), std_list.front());
  ASSERT_EQ(s21_list.back(), std_list.back());
}

TEST(s21_list_case, clear) {
  s21::List<float> s21_list{5, 4, 3, 2, 1};
  s21_list.clear();
  ASSERT_EQ(s21_list.size(), 0);

  s21::List<int> s21_list2;
  s21_list2.clear();
  ASSERT_EQ(s21_list2.size(), 0);
}

TEST(s21_list_case, insert_filled) {
  std::list<float> std_list{5, 4, 3, 2, 1};
  auto pos = std_list.begin();
  std_list.insert(pos, 777);
  std_list.insert(pos, 888);
  auto ins_pos = std_list.insert(pos, 999);

  s21::List<float> s21_list{5, 4, 3, 2, 1};
  auto pos21 = s21_list.begin();
  s21_list.insert(pos21, 777);
  s21_list.insert(pos21, 888);
  auto ins_pos_21 = s21_list.insert(pos21, 999);

  compare_lists(s21_list, std_list);
  ASSERT_EQ(*ins_pos_21, *ins_pos);
}

TEST(s21_list_case, insert_empty) {
  std::list<float> std_list;
  auto pos = std_list.begin();
  std_list.insert(pos, 555);
  std_list.insert(pos, 666);

  s21::List<float> s21_list;
  auto pos21 = s21_list.begin();
  s21_list.insert(pos21, 555);
  s21_list.insert(pos21, 666);

  compare_lists(s21_list, std_list);
}

TEST(s21_list_case, operator) {
  s21::List<float> std_list_y{1, 2, 3};
  auto pos = std_list_y.begin();
  auto pos1 = pos++;
  ASSERT_EQ(*pos1, 1);
  ASSERT_EQ(*pos, 2);
  pos1 = pos--;
  ASSERT_EQ(*pos1, 2);
  ASSERT_EQ(*pos, 1);
}

TEST(s21_list_case, erase) {
  std::initializer_list<float> data{1, 2, 3};
  s21::List<float> s21_list(data);
  std::list<float> std_list(data);
  auto p21 = s21_list.begin();
  ++p21;
  auto pstd = std_list.begin();
  ++pstd;
  s21_list.erase(p21);
  std_list.erase(pstd);
  ASSERT_EQ(s21_list.size(), std_list.size());
  compare_lists(s21_list, std_list);

  p21 = s21_list.end();
  pstd = std_list.end();
  --p21;
  --pstd;
  s21_list.erase(p21);
  std_list.erase(pstd);
  ASSERT_EQ(s21_list.size(), std_list.size());
  compare_lists(s21_list, std_list);

  p21 = s21_list.begin();
  pstd = std_list.begin();
  s21_list.erase(p21);
  std_list.erase(pstd);
  ASSERT_EQ(s21_list.size(), std_list.size());
  compare_lists(s21_list, std_list);
}

TEST(s21_list_case, push_pop) {
  std::initializer_list<float> data{5, 4, 3, 2, 1};
  s21::List<float> s21_list(data);
  std::list<float> std_list(data);

  s21_list.push_back(777);
  std_list.push_back(777);
  ASSERT_EQ(s21_list.size(), std_list.size());
  compare_lists(s21_list, std_list);

  s21_list.pop_back();
  std_list.pop_back();
  ASSERT_EQ(s21_list.size(), std_list.size());
  compare_lists(s21_list, std_list);

  s21_list.push_front(888);
  std_list.push_front(888);
  ASSERT_EQ(s21_list.size(), std_list.size());
  compare_lists(s21_list, std_list);

  s21_list.pop_front();
  std_list.pop_front();
  ASSERT_EQ(s21_list.size(), std_list.size());
  compare_lists(s21_list, std_list);
}

TEST(s21_list_case, pop) {
  std::initializer_list<float> data{5};
  s21::List<float> s21_list(data);
  s21_list.pop_back();
  ASSERT_EQ(s21_list.size(), 0);
}

TEST(s21_list_case, swap) {
  std::initializer_list<float> data1{5, 4, 3, 2, 1};
  s21::List<float> s21_list1(data1);
  std::list<float> std_list1(data1);
  std::initializer_list<float> data2{6, 7, 8, 9, 10};
  s21::List<float> s21_list2(data2);
  std::list<float> std_list2(data2);
  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);
  compare_lists(s21_list1, std_list1);
  compare_lists(s21_list2, std_list2);
}

TEST(s21_list_case, merge) {
  std::initializer_list<float> data1{1, 2, 3, 7};
  s21::List<float> s21_list1(data1);
  std::list<float> std_list1(data1);
  std::initializer_list<float> data2{1, 4, 5, 6};
  s21::List<float> s21_list2(data2);
  std::list<float> std_list2(data2);
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  compare_lists(s21_list1, std_list1);
  compare_lists(s21_list2, std_list2);
}

TEST(s21_list_case, merge_empty) {
  s21::List<float> s21_list1{3, 2, 1};
  std::list<float> std_list1{3, 2, 1};
  s21::List<float> s21_list2;
  std::list<float> std_list2;
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  compare_lists(s21_list1, std_list1);
  compare_lists(s21_list2, std_list2);
}

TEST(s21_list_case, splice) {
  std::initializer_list<float> data1{1, 2, 3, 7};
  s21::List<float> s21_list1(data1);
  auto p21 = s21_list1.begin();
  ++p21;
  std::list<float> std_list1(data1);
  std::initializer_list<float> data2{1, 4, 5, 6};
  s21::List<float> s21_list2(data2);
  auto pstd = std_list1.begin();
  ++pstd;
  std::list<float> std_list2(data2);
  s21::List<float>::const_iterator p21_const(p21.ptr_);
  s21_list1.splice(p21_const, s21_list2);
  std_list1.splice(pstd, std_list2);
  compare_lists(s21_list1, std_list1);
  compare_lists(s21_list2, std_list2);
}

TEST(s21_list_case, reverse_1) {
  std::initializer_list<float> data1{1, 2, 3, 4, 5};
  s21::List<float> s21_list(data1);
  std::initializer_list<float> data2{5, 4, 3, 2, 1};
  std::list<float> std_list(data2);
  s21_list.reverse();
  compare_lists(s21_list, std_list);
}

TEST(s21_list_case, reverse_2) {
  std::initializer_list<float> data1{1, 2, 3, 4};
  s21::List<float> s21_list(data1);
  std::initializer_list<float> data2{4, 3, 2, 1};
  std::list<float> std_list(data2);
  s21_list.reverse();
  compare_lists(s21_list, std_list);
}

TEST(s21_list_case, unique) {
  s21::List<float> s21_list{2, 3, 2, 2, 2, 3, 4, 2};
  std::list<float> std_list{2, 3, 2, 2, 2, 3, 4, 2};
  // 2 3 2 3 4 2
  s21_list.unique();
  std_list.unique();
  compare_lists(s21_list, std_list);
}

TEST(s21_list_case, sort) {
  s21::List<float> s21_list{5, 4, 3, 2, 1};
  std::list<float> std_list{5, 4, 3, 2, 1};
  s21_list.sort();
  std_list.sort();
  compare_lists(s21_list, std_list);
}

TEST(s21_list_case, insert_many) {
  s21::List<float> s21_list{5, 4, 3, 2, 1};
  std::list<float> std_list{5, 6, 7, 8, 4, 3, 2, 1};
  auto pos = s21_list.begin();
  ++pos;
  s21::List<float>::const_iterator pos_const(pos.ptr_);
  auto result = s21_list.insert_many(pos_const, 6, 7, 8);
  ASSERT_EQ(*result, 8);
  compare_lists(s21_list, std_list);

  s21_list.insert_many_back(444, 555, 666);
  std::list<float> insert_back{5, 6, 7, 8, 4, 3, 2, 1, 444, 555, 666};
  compare_lists(s21_list, insert_back);

  s21_list.insert_many_front(111, 222, 333);
  std::list<float> insert_front{333, 222, 111, 5, 6,   7,   8,
                                4,   3,   2,   1, 444, 555, 666};
  compare_lists(s21_list, insert_front);

  s21::List<float> s21_list1{};
  std::list<float> std_list1{5, 6};

  auto pos1 = s21_list1.begin();
  s21::List<float>::const_iterator pos_const1(pos1.ptr_);
  auto result1 = s21_list1.insert_many(pos_const1, 5, 6);
  ASSERT_EQ(*result1, 6);
  compare_lists(s21_list1, std_list1);
}

TEST(s21_list_case, end_throw) {
  s21::List<float> s21_list{};
  auto pos = s21_list.end();
  EXPECT_THROW(*pos, std::out_of_range);
}
