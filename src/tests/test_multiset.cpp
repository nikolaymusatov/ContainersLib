#include <set>

#include "test.h"

using namespace MyNamespace;

template <typename Key>
void compare_multiset(Multiset<Key> &multiset,
                      std::multiset<Key> &std_multiset) {
  auto i = multiset.begin();
  auto std_i = std_multiset.begin();
  while (i != multiset.end() || std_i != std_multiset.end()) {
    ASSERT_EQ(*i, *std_i);
    ++i;
    ++std_i;
  }
}

TEST(multiset_case, is_empty) {
  // default
  Multiset<int> multiset;
  std::multiset<int> std_multiset;
  ASSERT_EQ(multiset.empty(), std_multiset.empty());
}

TEST(multiset_case, multiset_default_ctor) {
  Multiset<int> multiset{10, 11, 12, 13, 14};
  std::multiset<int> std_multiset{10, 11, 12, 13, 14};
  ASSERT_EQ(multiset.size(), std_multiset.size());
  compare_multiset(multiset, std_multiset);
}

TEST(multiset_case, multiset_copy_ctor) {
  Multiset<int> multiset{1, 3, 7, 41, 52, 1, 67, 7};
  Multiset<int> multiset_copy = multiset;
  ASSERT_EQ(multiset_copy.size(), 8);
  ASSERT_EQ(multiset.size(), 8);
  int multiset_4_check[8] = {1, 1, 3, 7, 7, 41, 52, 67};
  int i = 0;
  for (auto it = multiset_copy.begin(); it != multiset_copy.end(); ++it) {
    ASSERT_EQ(*it, multiset_4_check[i]);
    i++;
  }
}

// copy move
TEST(multiset_case, multiset_copy_and_move) {
  Multiset<int> multiset{10, 11, 14, 13, 13, 10};
  std::multiset<int> std_multiset{10, 11, 14, 13, 13, 10};

  Multiset<int> multiset_copy(multiset);
  ASSERT_EQ(multiset_copy.size(), std_multiset.size());
  compare_multiset(multiset_copy, std_multiset);

  Multiset<int> multiset_move(std::move(multiset));
  ASSERT_EQ(multiset_move.size(), std_multiset.size());
  compare_multiset(multiset_move, std_multiset);
  ASSERT_TRUE(multiset.empty());
}

TEST(multiset_case, multiset_copy_operator) {
  Multiset<int> multiset;
  Multiset<int> multiset_copy{10, 11, 14};
  std::multiset<int> std_multiset{10, 11, 14};

  multiset = multiset_copy;
  ASSERT_EQ(multiset.size(), std_multiset.size());
  compare_multiset(multiset, std_multiset);
}

TEST(multiset_case, multiset_move_operator) {
  Multiset<int> multiset;
  Multiset<int> multiset_copy{10, 11, 14};
  std::multiset<int> std_multiset{10, 11, 14};

  multiset = std::move(multiset_copy);
  ASSERT_EQ(multiset.size(), std_multiset.size());
  compare_multiset(multiset, std_multiset);
}

TEST(multiset_case, multiset_add_and_erase) {
  Multiset<int> multiset{10};
  multiset.erase(multiset.find(10));
  ASSERT_TRUE(multiset.empty());
}

TEST(multiset_case, erase) {
  Multiset<int> multiset{32, 11, 7, 11, 4, 8, 52, 5, 22, 70, 70, 8};
  multiset.erase(multiset.find(100));
  multiset.erase(multiset.find(7));
  multiset.erase(multiset.find(11));
  multiset.erase(multiset.find(5));
  multiset.erase(multiset.find(32));
  multiset.erase(multiset.find(11));
  multiset.erase(multiset.find(4));
  multiset.erase(multiset.find(70));

  std::multiset<int> std_multiset{8, 52, 22, 70, 8};
  ASSERT_EQ(multiset.size(), std_multiset.size());
  compare_multiset(multiset, std_multiset);
  multiset.clear();
  ASSERT_TRUE(multiset.empty());
}

TEST(multiset_case, erase_root) {
  Multiset<int> multiset{32, 22};
  std::multiset<int> std_multiset{22};
  multiset.erase(multiset.find(32));
  compare_multiset(multiset, std_multiset);
}

TEST(multiset_case, max_size) {
  Multiset<int> multiset;
  ASSERT_EQ(multiset.max_size(),
            std::numeric_limits<size_t>::max() / sizeof(int));
}

TEST(multiset_case, contains) {
  Multiset<int> multiset{15, 3, 3, 7, 11};
  ASSERT_TRUE(multiset.contains(3));
  ASSERT_FALSE(multiset.contains(100));
}

TEST(multiset_case, insert) {
  Multiset<int> multiset{32, 11};
  multiset.insert(100);
  multiset.insert(7);
  multiset.insert(11);
  multiset.insert(7);

  std::multiset<int> std_multiset{32, 11, 100, 7, 11, 7};
  ASSERT_EQ(multiset.size(), std_multiset.size());
  compare_multiset(multiset, std_multiset);
  multiset.clear();
  ASSERT_TRUE(multiset.empty());
}

TEST(multiset_case, iterator) {
  Multiset<int> multiset{1, 2, 3};
  auto a = multiset.begin();
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

TEST(multiset_case, iterator1) {
  Multiset<int> multiset;
  auto a = multiset.begin();
  auto b = a++;
  Multiset<int> multiset1{7, 5, 6, 4};
  auto c = multiset1.begin();
  c++;
  c++;
  c++;
  auto d = --c;
  ASSERT_EQ((*d), 6);
}

TEST(multiset_case, insert_and_erase) {
  Multiset<int> multiset{4, 5, 4};
  multiset.insert(5);
  multiset.insert(1);
  multiset.erase(multiset.find(8));
  multiset.insert(4);
  multiset.insert(1);
  multiset.insert(8);

  multiset.erase(multiset.find(4));
  multiset.erase(multiset.find(5));
  multiset.erase(multiset.find(5));
  multiset.erase(multiset.find(4));
  multiset.erase(multiset.find(1));
  std::multiset<int> std_multiset{4, 1, 8};

  ASSERT_EQ(multiset.size(), std_multiset.size());
  compare_multiset(multiset, std_multiset);
}

TEST(multiset_case, merge) {
  Multiset<int> multiset{14, 1, 3, 1, 14};

  Multiset<int> multiset_merge{3, 14, 2};

  std::multiset<int> std_multiset{14, 1, 3, 1, 14, 3, 14, 2};

  multiset.merge(multiset_merge);
  compare_multiset(multiset, std_multiset);
  ASSERT_EQ(multiset.size(), std_multiset.size());
  ASSERT_TRUE(multiset_merge.empty());
}

TEST(multiset_case, insert_many) {
  Multiset<int> multiset{2, 3, 2, 1};

  std::vector<std::pair<Multiset<int>::iterator, bool>> res =
      multiset.insert_many(2, 1, 4, 5);

  std::multiset<int> std_multiset{2, 3, 2, 1, 2, 1, 4, 5};

  compare_multiset(multiset, std_multiset);
  ASSERT_EQ(multiset.size(), std_multiset.size());

  // for (auto item : res) {
  //     std::cout << item.first->second << std::endl;
  // }
}

TEST(multiset_case, count) {
  Multiset<int> multiset{2, 3, 2, 3, 4, 3};
  ASSERT_EQ(multiset.count(3), 3);
}

TEST(multiset_case, lower_bound) {
  Multiset<int> multiset{2, 3, 2, 3, 4, 4};
  std::multiset<int> std_multiset{2, 3, 2, 3, 4, 4};

  auto res = multiset.lower_bound(3);
  auto std_res = std_multiset.lower_bound(3);

  ASSERT_EQ(*res, *std_res);
}

TEST(multiset_case, upper_bound) {
  Multiset<int> multiset{2, 3, 2, 3, 4, 4};
  std::multiset<int> std_multiset{2, 3, 2, 3, 4, 4};

  auto res = multiset.upper_bound(3);
  auto std_res = std_multiset.upper_bound(3);

  ASSERT_EQ(*res, *std_res);
}

TEST(multiset_case, equal_range) {
  Multiset<int> multiset{3, 3, 7, 6, 8};
  std::pair<Multiset<int>::iterator, Multiset<int>::iterator> res =
      multiset.equal_range(3);

  ASSERT_EQ(*res.first, 3);
  ASSERT_EQ(*res.second, 6);
}