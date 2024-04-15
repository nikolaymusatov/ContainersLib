#include "test.h"

using namespace MyNamespace;

template <typename Key>
void compare_set(Set<Key> &set, std::set<Key> &std_set) {
  auto i = set.begin();
  auto std_i = std_set.begin();
  while (i != set.end() || std_i != std_set.end()) {
    ASSERT_EQ(*i, *std_i);
    ++i;
    ++std_i;
  }
}

TEST(Set_Empty, Test_1) {
  Set<int> s;
  s.insert(1);
  s.insert(2);
  ASSERT_TRUE(s.empty() == false);
}

TEST(Set_Empty, Test_2) {
  Set<int> s;
  ASSERT_TRUE(s.empty() == true);
}

TEST(Set_Empty, Test_3) {
  Set<int> s{2, 3};
  s.erase(s.find(2));
  s.erase(s.find(3));
  ASSERT_TRUE(s.empty() == true);
}

TEST(Set_Empty, Test_4) {
  Set<std::string> s;
  s.insert("1");
  s.erase(s.find("1"));
  ASSERT_TRUE(s.empty() == true);
}

TEST(Set_Size, Test_1) {
  Set<int> s;
  ASSERT_TRUE(s.size() == 0);
}

TEST(Set_Size, Test_2) {
  Set<int> s{6, 2, 5, 3};
  ASSERT_TRUE(s.size() == 4);
}

TEST(Set_Size, Test_3) {
  Set<int> s{6, 2, 5, 3};
  s.insert(8);
  ASSERT_TRUE(s.size() == 5);
}

TEST(Set_Size, Test_4) {
  Set<int> s{6, 2, 5, 3};
  s.erase(s.find(2));
  ASSERT_TRUE(s.size() == 3);
}

TEST(Set_Clear, Test_1) {
  Set<int> s{6, 2, 5, 3};
  s.clear();
  ASSERT_TRUE(s.size() == 0);
}

TEST(Set_Clear, Test_2) {
  Set<char> s{'6', '2', '5', '3'};
  s.clear();
  ASSERT_TRUE(s.size() == 0);
}

TEST(Set_Swap, Test_1) {
  Set<int> s1{6, 2, 5, 3};
  Set<int> s2;
  s2.swap(s1);
  ASSERT_TRUE(s1.empty() == true);
  ASSERT_TRUE(s1.size() == 0);
  ASSERT_TRUE(s2.size() == 4);
}

TEST(Set_Swap, Test_2) {
  Set<int> s1{6, 2, 5, 3};
  Set<int> s2{9, 2, 7};
  s2.swap(s1);
  ASSERT_TRUE(s1.size() == 3);
  ASSERT_TRUE(s2.size() == 4);
}

TEST(Set_Merge, Test_1) {
  Set<int> s1{6, 2, 5, 3};
  Set<int> s2{9, 2, 7};
  s1.merge(s2);
  ASSERT_TRUE(s1.size() == 6);
  ASSERT_TRUE(s2.size() == 1);
}

TEST(Set_Merge, Test_2) {
  Set<int> s1{6, 2, 5, 3};
  Set<int> s2{6, 2, 5, 3};
  s1.merge(s2);
  ASSERT_TRUE(s1.size() == 4);
  ASSERT_TRUE(s2.size() == 4);
}

TEST(Set_Merge, Test_3) {
  Set<int> s1{6, 2, 5, 3};
  Set<int> s2{1, 7, 4};
  s1.merge(s2);
  ASSERT_TRUE(s1.size() == 7);
  ASSERT_TRUE(s2.size() == 0);
}

TEST(Set_Contains, Test_1) {
  Set<int> s{6, 2, 5, 3};
  ASSERT_TRUE(s.contains(6) == true);
}

TEST(Set_Contains, Test_2) {
  Set<int> s{6, 2, 5, 3};
  ASSERT_TRUE(s.contains(9) == false);
}

TEST(Set_Contains, Test_3) {
  Set<std::string> s{"carisafi", "peachgha", "greapfru"};
  ASSERT_TRUE(s.contains("carisafi") == true);
}

TEST(Set_Contains, Test_4) {
  Set<std::string> s{"carisafi", "peachgha", "greapfru"};
  ASSERT_TRUE(s.contains("containers") == false);
}

TEST(Set_Find, Test_1) {
  Set<std::string> s{"carisafi", "peachgha", "greapfru"};
  auto iter = s.begin();
  while (*iter != "greapfru") iter++;
  ASSERT_TRUE(iter == s.find("greapfru"));
}

TEST(Set_Find, Test_2) {
  Set<std::string> s{"carisafi", "peachgha", "greapfru"};
  auto iter = s.begin();
  while (iter != s.end() && *iter != "contariners") iter++;
  ASSERT_TRUE(iter == s.find("containers"));
}

TEST(Set_Find, Test_3) {
  Set<std::string> s{"carisafi", "peachgha", "greapfru"};
  auto iter = s.end();
  ASSERT_TRUE(iter == s.find("containers"));
}

TEST(Set_Constructor, Test_1) {
  Set<std::string> s{"carisafi", "peachgha", "greapfru"};
  Set<std::string> s2(s);
  ASSERT_TRUE(s2.size() == 3);
}

TEST(Set_Constructor, Test_2) {
  Set<std::string> s{"carisafi", "peachgha", "greapfru"};
  Set<std::string> s2(std::move(s));
  ASSERT_TRUE(s2.size() == 3);
  ASSERT_TRUE(s.size() == 0);
}

TEST(Set_Operator, Test_1) {
  Set<std::string> s{"carisafi", "peachgha", "greapfru"};
  Set<std::string> s2 = s;
  ASSERT_TRUE(s2.size() == 3);
}

TEST(Set_Operator, Test_2) {
  Set<int> set;
  Set<int> set_copy{1, 2, 3};
  std::set<int> std_set{1, 2, 3};

  set = set_copy;
  compare_set(set, std_set);
}

TEST(Set_Operator, Test_3) {
  Set<int> set;
  Set<int> set_copy{1, 2, 3};
  std::set<int> std_set{1, 2, 3};

  set = std::move(set_copy);
  compare_set(set, std_set);
}

TEST(Set_Max_Size, Test_1) {
  Set<int> set;
  ASSERT_EQ(set.max_size(), std::numeric_limits<size_t>::max() / sizeof(int));
}

TEST(Set_Begin_End, Test_1) {
  Set<int> set{1, 2, 3};
  auto pos1 = set.cbegin();
  auto pos2 = set.cend();
  ASSERT_EQ(*pos1, 1);
}

TEST(Set_Insert_Many, Test_1) {
  Set<int> set{2, 3, 2, 1};
  std::vector<std::pair<Set<int>::iterator, bool>> res =
      set.insert_many(2, 1, 4, 5);
  std::set<int> std_set{2, 3, 1, 4, 5};
  compare_set(set, std_set);
  ASSERT_EQ(set.size(), std_set.size());
}
