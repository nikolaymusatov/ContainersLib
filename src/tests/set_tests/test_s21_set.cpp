#include "test_s21_main.h"

using namespace s21;

template <typename Key>
void compare_set(set<Key> &s21_multiset, std::set<Key> &std_multiset) {
  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  while (s21_i != s21_multiset.end() || std_i != std_multiset.end()) {
    ASSERT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
}

TEST(Set_Empty, Test_1) {
  set<int> s;
  s.insert(1);
  s.insert(2);
  ASSERT_TRUE(s.empty() == false);
}

TEST(Set_Empty, Test_2) {
  set<int> s;
  ASSERT_TRUE(s.empty() == true);
}

TEST(Set_Empty, Test_3) {
  set<int> s{2, 3};
  s.erase(s.find(2));
  s.erase(s.find(3));
  ASSERT_TRUE(s.empty() == true);
}

TEST(Set_Empty, Test_4) {
  set<std::string> s;
  s.insert("1");
  s.erase(s.find("1"));
  ASSERT_TRUE(s.empty() == true);
}

TEST(Set_Size, Test_1) {
  set<int> s;
  ASSERT_TRUE(s.size() == 0);
}

TEST(Set_Size, Test_2) {
  set<int> s{6, 2, 5, 3};
  ASSERT_TRUE(s.size() == 4);
}

TEST(Set_Size, Test_3) {
  set<int> s{6, 2, 5, 3};
  s.insert(8);
  ASSERT_TRUE(s.size() == 5);
}

TEST(Set_Size, Test_4) {
  set<int> s{6, 2, 5, 3};
  s.erase(s.find(2));
  ASSERT_TRUE(s.size() == 3);
}

TEST(Set_Clear, Test_1) {
  set<int> s{6, 2, 5, 3};
  s.clear();
  ASSERT_TRUE(s.size() == 0);
}

TEST(Set_Clear, Test_2) {
  set<char> s{'6', '2', '5', '3'};
  s.clear();
  ASSERT_TRUE(s.size() == 0);
}

TEST(Set_Swap, Test_1) {
  set<int> s1{6, 2, 5, 3};
  set<int> s2;
  s2.swap(s1);
  ASSERT_TRUE(s1.empty() == true);
  ASSERT_TRUE(s1.size() == 0);
  ASSERT_TRUE(s2.size() == 4);
}

TEST(Set_Swap, Test_2) {
  set<int> s1{6, 2, 5, 3};
  set<int> s2{9, 2, 7};
  s2.swap(s1);
  ASSERT_TRUE(s1.size() == 3);
  ASSERT_TRUE(s2.size() == 4);
}

TEST(Set_Merge, Test_1) {
  set<int> s1{6, 2, 5, 3};
  set<int> s2{9, 2, 7};
  s1.merge(s2);
  ASSERT_TRUE(s1.size() == 6);
  ASSERT_TRUE(s2.size() == 1);
}

TEST(Set_Merge, Test_2) {
  set<int> s1{6, 2, 5, 3};
  set<int> s2{6, 2, 5, 3};
  s1.merge(s2);
  ASSERT_TRUE(s1.size() == 4);
  ASSERT_TRUE(s2.size() == 4);
}

TEST(Set_Merge, Test_3) {
  set<int> s1{6, 2, 5, 3};
  set<int> s2{1, 7, 4};
  s1.merge(s2);
  ASSERT_TRUE(s1.size() == 7);
  ASSERT_TRUE(s2.size() == 0);
}

TEST(Set_Contains, Test_1) {
  set<int> s{6, 2, 5, 3};
  ASSERT_TRUE(s.contains(6) == true);
}

TEST(Set_Contains, Test_2) {
  set<int> s{6, 2, 5, 3};
  ASSERT_TRUE(s.contains(9) == false);
}

TEST(Set_Contains, Test_3) {
  set<std::string> s{"carisafi", "peachgha", "greapfru"};
  ASSERT_TRUE(s.contains("carisafi") == true);
}

TEST(Set_Contains, Test_4) {
  set<std::string> s{"carisafi", "peachgha", "greapfru"};
  ASSERT_TRUE(s.contains("containers") == false);
}

TEST(Set_Find, Test_1) {
  set<std::string> s{"carisafi", "peachgha", "greapfru"};
  auto iter = s.begin();
  while (*iter != "greapfru") iter++;
  ASSERT_TRUE(iter == s.find("greapfru"));
}

TEST(Set_Find, Test_2) {
  set<std::string> s{"carisafi", "peachgha", "greapfru"};
  auto iter = s.begin();
  while (iter != s.end() && *iter != "contariners") iter++;
  ASSERT_TRUE(iter == s.find("containers"));
}

TEST(Set_Find, Test_3) {
  set<std::string> s{"carisafi", "peachgha", "greapfru"};
  auto iter = s.end();
  ASSERT_TRUE(iter == s.find("containers"));
}

TEST(Set_Constructor, Test_1) {
  set<std::string> s{"carisafi", "peachgha", "greapfru"};
  set<std::string> s2(s);
  ASSERT_TRUE(s2.size() == 3);
}

TEST(Set_Constructor, Test_2) {
  set<std::string> s{"carisafi", "peachgha", "greapfru"};
  set<std::string> s2(std::move(s));
  ASSERT_TRUE(s2.size() == 3);
  ASSERT_TRUE(s.size() == 0);
}

TEST(Set_Operator, Test_1) {
  set<std::string> s{"carisafi", "peachgha", "greapfru"};
  set<std::string> s2 = s;
  ASSERT_TRUE(s2.size() == 3);
}

TEST(Set_Operator, Test_2) {
  set<int> s21_set;
  set<int> s21_set_copy{1, 2, 3};
  std::set<int> std_set{1, 2, 3};

  s21_set = s21_set_copy;
  compare_set(s21_set, std_set);
}

TEST(Set_Operator, Test_3) {
  set<int> s21_set;
  set<int> s21_set_copy{1, 2, 3};
  std::set<int> std_set{1, 2, 3};

  s21_set = std::move(s21_set_copy);
  compare_set(s21_set, std_set);
}

TEST(Set_Max_Size, Test_1) {
  set<int> s21_set;
  ASSERT_EQ(s21_set.max_size(),
            std::numeric_limits<size_t>::max() / sizeof(int));
}

TEST(Set_Begin_End, Test_1) {
  set<int> s21_set{1, 2, 3};
  auto pos1 = s21_set.cbegin();
  auto pos2 = s21_set.cend();
  ASSERT_EQ(*pos1, 1);
  // ASSERT_EQ(*pos2, nullptr);
}

TEST(Set_Insert_Many, Test_1) {
  s21::set<int> s21_set{2, 3, 2, 1};

  std::vector<std::pair<s21::set<int>::iterator, bool>> res =
      s21_set.insert_many(2, 1, 4, 5);

  std::set<int> std_set{2, 3, 1, 4, 5};

  compare_set(s21_set, std_set);
  ASSERT_EQ(s21_set.size(), std_set.size());
}
