#include <set>

#include "test_s21_main.h"

template <typename Key>
void compare_multiset(s21::multiset<Key> &s21_multiset,
                      std::multiset<Key> &std_multiset) {
  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  while (s21_i != s21_multiset.end() || std_i != std_multiset.end()) {
    ASSERT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
}

TEST(s21_multiset_case, is_empty) {
  // default
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  ASSERT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(s21_multiset_case, multiset_default_ctor) {
  s21::multiset<int> s21_multiset{10, 11, 12, 13, 14};
  std::multiset<int> std_multiset{10, 11, 12, 13, 14};
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  compare_multiset(s21_multiset, std_multiset);
}

TEST(s21_multiset_case, multiset_copy_ctor) {
  s21::multiset<int> s21_multiset{1, 3, 7, 41, 52, 1, 67, 7};
  s21::multiset<int> s21_multiset_copy = s21_multiset;
  ASSERT_EQ(s21_multiset_copy.size(), 8);
  ASSERT_EQ(s21_multiset.size(), 8);
  int multiset_4_check[8] = {1, 1, 3, 7, 7, 41, 52, 67};
  int i = 0;
  for (auto it = s21_multiset_copy.begin(); it != s21_multiset_copy.end();
       ++it) {
    ASSERT_EQ(*it, multiset_4_check[i]);
    i++;
  }
}

// copy move
TEST(s21_multiset_case, multiset_copy_and_move) {
  s21::multiset<int> s21_multiset{10, 11, 14, 13, 13, 10};
  std::multiset<int> std_multiset{10, 11, 14, 13, 13, 10};

  s21::multiset<int> s21_multiset_copy(s21_multiset);
  ASSERT_EQ(s21_multiset_copy.size(), std_multiset.size());
  compare_multiset(s21_multiset_copy, std_multiset);

  s21::multiset<int> s21_multiset_move(std::move(s21_multiset));
  ASSERT_EQ(s21_multiset_move.size(), std_multiset.size());
  compare_multiset(s21_multiset_move, std_multiset);
  ASSERT_TRUE(s21_multiset.empty());
}

TEST(s21_multiset_case, multiset_copy_operator) {
  s21::multiset<int> s21_multiset;
  s21::multiset<int> s21_multiset_copy{10, 11, 14};
  std::multiset<int> std_multiset{10, 11, 14};

  s21_multiset = s21_multiset_copy;
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  compare_multiset(s21_multiset, std_multiset);
}

TEST(s21_multiset_case, multiset_move_operator) {
  s21::multiset<int> s21_multiset;
  s21::multiset<int> s21_multiset_copy{10, 11, 14};
  std::multiset<int> std_multiset{10, 11, 14};

  s21_multiset = std::move(s21_multiset_copy);
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  compare_multiset(s21_multiset, std_multiset);
}

TEST(s21_multiset_case, multiset_add_and_erase) {
  s21::multiset<int> s21_multiset{10};
  s21_multiset.erase(s21_multiset.find(10));
  ASSERT_TRUE(s21_multiset.empty());
}

TEST(s21_multiset_case, erase) {
  s21::multiset<int> s21_multiset{32, 11, 7, 11, 4, 8, 52, 5, 22, 70, 70, 8};
  s21_multiset.erase(s21_multiset.find(100));
  s21_multiset.erase(s21_multiset.find(7));
  s21_multiset.erase(s21_multiset.find(11));
  s21_multiset.erase(s21_multiset.find(5));
  s21_multiset.erase(s21_multiset.find(32));
  s21_multiset.erase(s21_multiset.find(11));
  s21_multiset.erase(s21_multiset.find(4));
  s21_multiset.erase(s21_multiset.find(70));

  std::multiset<int> std_multiset{8, 52, 22, 70, 8};
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  compare_multiset(s21_multiset, std_multiset);
  s21_multiset.clear();
  ASSERT_TRUE(s21_multiset.empty());
}

TEST(s21_multiset_case, erase_root) {
  s21::multiset<int> s21_multiset{32, 22};
  std::multiset<int> std_multiset{22};
  s21_multiset.erase(s21_multiset.find(32));
  compare_multiset(s21_multiset, std_multiset);
}

TEST(s21_multiset_case, max_size) {
  s21::multiset<int> s21_multiset;
  ASSERT_EQ(s21_multiset.max_size(),
            std::numeric_limits<size_t>::max() / sizeof(int));
}

TEST(s21_multiset_case, contains) {
  s21::multiset<int> s21_multiset{15, 3, 3, 7, 11};
  ASSERT_TRUE(s21_multiset.contains(3));
  ASSERT_FALSE(s21_multiset.contains(100));
}

TEST(s21_multiset_case, insert) {
  s21::multiset<int> s21_multiset{32, 11};
  s21_multiset.insert(100);
  s21_multiset.insert(7);
  s21_multiset.insert(11);
  s21_multiset.insert(7);

  std::multiset<int> std_multiset{32, 11, 100, 7, 11, 7};
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  compare_multiset(s21_multiset, std_multiset);
  s21_multiset.clear();
  ASSERT_TRUE(s21_multiset.empty());
}

TEST(s21_multiset_case, iterator) {
  s21::multiset<int> s21_multiset{1, 2, 3};
  auto a = s21_multiset.begin();
  auto a_inf_incr = ++a;
  ASSERT_EQ((*a_inf_incr), 2);

  auto a_post_incr = a++;
  ASSERT_EQ((*a_post_incr), 2);

  auto a_inf_decr = --a;
  ASSERT_EQ((*a_inf_decr), 2);
  ASSERT_EQ((*a), 2);

  auto a_post_decr = a--;
  ASSERT_EQ((*a_post_decr), 2);
  ASSERT_EQ((*a), 1);
}

TEST(s21_multiset_case, iterator1) {
  s21::multiset<int> s21_multiset;
  auto a = s21_multiset.begin();
  auto b = a++;
  s21::multiset<int> s21_multiset1{7, 5, 6, 4};
  auto c = s21_multiset1.begin();
  c++;
  c++;
  c++;
  auto d = --c;
  ASSERT_EQ((*d), 6);
}

TEST(s21_multiset_case, insert_and_erase) {
  s21::multiset<int> s21_multiset{4, 5, 4};
  s21_multiset.insert(5);
  s21_multiset.insert(1);
  s21_multiset.erase(s21_multiset.find(8));
  s21_multiset.insert(4);
  s21_multiset.insert(1);
  s21_multiset.insert(8);

  s21_multiset.erase(s21_multiset.find(4));
  s21_multiset.erase(s21_multiset.find(5));
  s21_multiset.erase(s21_multiset.find(5));
  s21_multiset.erase(s21_multiset.find(4));
  s21_multiset.erase(s21_multiset.find(1));
  std::multiset<int> std_multiset{4, 1, 8};

  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  compare_multiset(s21_multiset, std_multiset);
}

TEST(s21_multiset_case, merge) {
  s21::multiset<int> s21_multiset{14, 1, 3, 1, 14};

  s21::multiset<int> s21_multiset_merge{3, 14, 2};

  std::multiset<int> std_multiset{14, 1, 3, 1, 14, 3, 14, 2};

  s21_multiset.merge(s21_multiset_merge);
  compare_multiset(s21_multiset, std_multiset);
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
  ASSERT_TRUE(s21_multiset_merge.empty());
}

TEST(s21_multiset_case, insert_many) {
  s21::multiset<int> s21_multiset{2, 3, 2, 1};

  std::vector<std::pair<s21::multiset<int>::iterator, bool>> res =
      s21_multiset.insert_many(2, 1, 4, 5);

  std::multiset<int> std_multiset{2, 3, 2, 1, 2, 1, 4, 5};

  compare_multiset(s21_multiset, std_multiset);
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());

  // for (auto item : res) {
  //     std::cout << item.first->second << std::endl;
  // }
}

TEST(s21_multiset_case, count) {
  s21::multiset<int> s21_multiset{2, 3, 2, 3, 4, 3};
  ASSERT_EQ(s21_multiset.count(3), 3);
}

TEST(s21_multiset_case, lower_bound) {
  s21::multiset<int> s21_multiset{2, 3, 2, 3, 4, 4};
  std::multiset<int> std_multiset{2, 3, 2, 3, 4, 4};

  auto s21_res = s21_multiset.lower_bound(3);
  auto std_res = std_multiset.lower_bound(3);

  ASSERT_EQ(*s21_res, *std_res);
}

TEST(s21_multiset_case, upper_bound) {
  s21::multiset<int> s21_multiset{2, 3, 2, 3, 4, 4};
  std::multiset<int> std_multiset{2, 3, 2, 3, 4, 4};

  auto s21_res = s21_multiset.upper_bound(3);
  auto std_res = std_multiset.upper_bound(3);

  ASSERT_EQ(*s21_res, *std_res);
}

TEST(s21_multiset_case, equal_range) {
  s21::multiset<int> s21_multiset{3, 3, 7, 6, 8};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> res =
      s21_multiset.equal_range(3);

  ASSERT_EQ(*res.first, 3);
  ASSERT_EQ(*res.second, 6);
}