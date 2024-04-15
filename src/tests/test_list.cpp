#include <list>

#include "test.h"

using namespace MyNamespace;

void compare_lists(List<float> const &list, std::list<float> const &std_list) {
  auto i = list.begin();
  auto std_i = std_list.begin();
  while (i != list.end() || std_i != std_list.end()) {
    ASSERT_EQ(i, *std_i);
    ++i;
    ++std_i;
  }
}

TEST(list_case, ctor_empty) {
  // default
  List<float> list;
  std::list<float> std_list;
  ASSERT_EQ(list.empty(), std_list.empty());
}

TEST(list_case, ctor_parameterized) {
  // parameterized
  List<float> list(3);
  std::list<float> std_list(3);
  ASSERT_EQ(list.size(), std_list.size());
  compare_lists(list, std_list);
}

TEST(ist_case, ctors_size) {
  // initializer_list
  List<float> list{5, 4, 3, 2, 1};
  std::list<float> std_list{5, 4, 3, 2, 1};
  ASSERT_EQ(list.size(), std_list.size());
  compare_lists(list, std_list);

  // test for iterator loop
  auto pos = list.end();
  ++pos;
  auto std_pos = std_list.end();
  ++std_pos;
  ASSERT_EQ(*pos, *std_pos);

  // copy
  List<float> list_copy(list);
  std::list<float> std_list_copy(std_list);
  ASSERT_EQ(list_copy.size(), std_list_copy.size());
  compare_lists(list_copy, std_list_copy);

  // move operator
  List<float> list1{1, 2, 3, 4, 5};
  list1 = std::move(list_copy);
  std::list<float> std_list1{5, 4, 3, 2, 1};
  ASSERT_EQ(list1.size(), std_list1.size());
  compare_lists(list1, std_list1);

  // move constructor
  List<float> list2(std::move(list1));
  std::list<float> std_list2(std::move(std_list1));
  ASSERT_EQ(list2.size(), std_list2.size());
  compare_lists(list2, std_list2);
}

TEST(list_case, copy_operator) {
  List<float> list{5};
  List<float> list_copy;
  std::list<float> std_list{5};

  list_copy = list;
  compare_lists(list, std_list);
}

TEST(list_case, front_back) {
  List<float> list{5, 4, 3, 2, 1};
  std::list<float> std_list{5, 4, 3, 2, 1};
  ASSERT_EQ(list.front(), std_list.front());
  ASSERT_EQ(list.back(), std_list.back());
}

TEST(list_case, clear) {
  List<float> list{5, 4, 3, 2, 1};
  list.clear();
  ASSERT_EQ(list.size(), 0);

  List<int> list2;
  list2.clear();
  ASSERT_EQ(list2.size(), 0);
}

TEST(list_case, insert_filled) {
  std::list<float> std_list{5, 4, 3, 2, 1};
  auto std_pos = std_list.begin();
  std_list.insert(std_pos, 777);
  std_list.insert(std_pos, 888);
  auto ins_std_pos = std_list.insert(std_pos, 999);

  List<float> list{5, 4, 3, 2, 1};
  auto pos = list.begin();
  list.insert(pos, 777);
  list.insert(pos, 888);
  auto ins_pos = list.insert(pos, 999);

  compare_lists(list, std_list);
  ASSERT_EQ(*ins_pos, *ins_std_pos);
}

TEST(list_case, insert_empty) {
  std::list<float> std_list;
  auto std_pos = std_list.begin();
  std_list.insert(std_pos, 555);
  std_list.insert(std_pos, 666);

  List<float> list;
  auto pos = list.begin();
  list.insert(pos, 555);
  list.insert(pos, 666);

  compare_lists(list, std_list);
}

TEST(list_case, operator) {
  List<float> list_y{1, 2, 3};
  auto pos = list_y.begin();
  auto pos1 = pos++;
  ASSERT_EQ(*pos1, 1);
  ASSERT_EQ(*pos, 2);
  pos1 = pos--;
  ASSERT_EQ(*pos1, 2);
  ASSERT_EQ(*pos, 1);
}

TEST(list_case, erase) {
  std::initializer_list<float> data{1, 2, 3};
  List<float> list(data);
  std::list<float> std_list(data);
  auto p = list.begin();
  ++p;
  auto pstd = std_list.begin();
  ++pstd;
  list.erase(p);
  std_list.erase(pstd);
  ASSERT_EQ(list.size(), std_list.size());
  compare_lists(list, std_list);

  p = list.end();
  pstd = std_list.end();
  --p;
  --pstd;
  list.erase(p);
  std_list.erase(pstd);
  ASSERT_EQ(list.size(), std_list.size());
  compare_lists(list, std_list);

  p = list.begin();
  pstd = std_list.begin();
  list.erase(p);
  std_list.erase(pstd);
  ASSERT_EQ(list.size(), std_list.size());
  compare_lists(list, std_list);
}

TEST(s21_list_case, push_pop) {
  std::initializer_list<float> data{5, 4, 3, 2, 1};
  List<float> list(data);
  std::list<float> std_list(data);

  list.push_back(777);
  std_list.push_back(777);
  ASSERT_EQ(list.size(), std_list.size());
  compare_lists(list, std_list);

  list.pop_back();
  std_list.pop_back();
  ASSERT_EQ(list.size(), std_list.size());
  compare_lists(list, std_list);

  list.push_front(888);
  std_list.push_front(888);
  ASSERT_EQ(list.size(), std_list.size());
  compare_lists(list, std_list);

  list.pop_front();
  std_list.pop_front();
  ASSERT_EQ(list.size(), std_list.size());
  compare_lists(list, std_list);
}

TEST(list_case, pop) {
  std::initializer_list<float> data{5};
  List<float> list(data);
  list.pop_back();
  ASSERT_EQ(list.size(), 0);
}

TEST(list_case, swap) {
  std::initializer_list<float> data1{5, 4, 3, 2, 1};
  List<float> list1(data1);
  std::list<float> std_list1(data1);
  std::initializer_list<float> data2{6, 7, 8, 9, 10};
  List<float> list2(data2);
  std::list<float> std_list2(data2);
  list1.swap(list2);
  std_list1.swap(std_list2);
  compare_lists(list1, std_list1);
  compare_lists(list2, std_list2);
}

TEST(list_case, merge) {
  std::initializer_list<float> data1{1, 2, 3, 7};
  List<float> list1(data1);
  std::list<float> std_list1(data1);
  std::initializer_list<float> data2{1, 4, 5, 6};
  List<float> list2(data2);
  std::list<float> std_list2(data2);
  list1.merge(list2);
  std_list1.merge(std_list2);
  compare_lists(list1, std_list1);
  compare_lists(list2, std_list2);
}

TEST(s21_list_case, merge_empty) {
  List<float> list1{3, 2, 1};
  std::list<float> std_list1{3, 2, 1};
  List<float> list2;
  std::list<float> std_list2;
  list1.merge(list2);
  std_list1.merge(std_list2);
  compare_lists(list1, std_list1);
  compare_lists(list2, std_list2);
}

TEST(s21_list_case, splice) {
  std::initializer_list<float> data1{1, 2, 3, 7};
  List<float> list1(data1);
  auto p = list1.begin();
  ++p;
  std::list<float> std_list1(data1);
  std::initializer_list<float> data2{1, 4, 5, 6};
  List<float> list2(data2);
  auto pstd = std_list1.begin();
  ++pstd;
  std::list<float> std_list2(data2);
  List<float>::const_iterator p_const(p.ptr_);
  list1.splice(p_const, list2);
  std_list1.splice(pstd, std_list2);
  compare_lists(list1, std_list1);
  compare_lists(list2, std_list2);
}

TEST(s21_list_case, reverse_1) {
  std::initializer_list<float> data1{1, 2, 3, 4, 5};
  List<float> list(data1);
  std::initializer_list<float> data2{5, 4, 3, 2, 1};
  std::list<float> std_list(data2);
  list.reverse();
  compare_lists(list, std_list);
}

TEST(list_case, reverse_2) {
  std::initializer_list<float> data1{1, 2, 3, 4};
  List<float> list(data1);
  std::initializer_list<float> data2{4, 3, 2, 1};
  std::list<float> std_list(data2);
  list.reverse();
  compare_lists(list, std_list);
}

TEST(list_case, unique) {
  List<float> list{2, 3, 2, 2, 2, 3, 4, 2};
  std::list<float> std_list{2, 3, 2, 2, 2, 3, 4, 2};
  list.unique();
  std_list.unique();
  compare_lists(list, std_list);
}

TEST(list_case, sort) {
  List<float> list{5, 4, 3, 2, 1};
  std::list<float> std_list{5, 4, 3, 2, 1};
  list.sort();
  std_list.sort();
  compare_lists(list, std_list);
}

TEST(list_case, insert_many) {
  List<float> list{5, 4, 3, 2, 1};
  std::list<float> std_list{5, 6, 7, 8, 4, 3, 2, 1};
  auto pos = list.begin();
  ++pos;
  List<float>::const_iterator pos_const(pos.ptr_);
  auto result = list.insert_many(pos_const, 6, 7, 8);
  ASSERT_EQ(*result, 8);
  compare_lists(list, std_list);

  list.insert_many_back(444, 555, 666);
  std::list<float> insert_back{5, 6, 7, 8, 4, 3, 2, 1, 444, 555, 666};
  compare_lists(list, insert_back);

  list.insert_many_front(111, 222, 333);
  std::list<float> insert_front{333, 222, 111, 5, 6,   7,   8,
                                4,   3,   2,   1, 444, 555, 666};
  compare_lists(list, insert_front);

  List<float> list1{};
  std::list<float> std_list1{5, 6};

  auto pos1 = list1.begin();
  List<float>::const_iterator pos_const1(pos1.ptr_);
  auto result1 = list1.insert_many(pos_const1, 5, 6);
  ASSERT_EQ(*result1, 6);
  compare_lists(list1, std_list1);
}

TEST(list_case, end_throw) {
  List<float> list{};
  auto pos = list.end();
  EXPECT_THROW(*pos, std::out_of_range);
}
