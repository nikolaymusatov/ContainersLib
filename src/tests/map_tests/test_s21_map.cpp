#include <map>

#include "test_s21_main.h"

template <typename Key, typename T>
void compare_map(s21::map<Key, T> &s21_map, std::map<Key, T> &std_map) {
  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  while (s21_i != s21_map.end() || std_i != std_map.end()) {
    ASSERT_EQ(s21_i->first, std_i->first);
    ASSERT_EQ(s21_i->second, std_i->second);
    ++s21_i;
    ++std_i;
  }
}

TEST(s21_map_case, is_empty) {
  // default
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  ASSERT_EQ(s21_map.empty(), std_map.empty());
}

TEST(s21_map_case, map_default_ctor) {
  s21::map<int, int> s21_map{std::make_pair(10, 10), std::make_pair(11, 9),
                             std::make_pair(12, 8),  std::make_pair(13, 7),
                             std::make_pair(14, 6),  std::make_pair(15, 5)};
  std::map<int, int> std_map{std::make_pair(10, 10), std::make_pair(11, 9),
                             std::make_pair(12, 8),  std::make_pair(13, 7),
                             std::make_pair(14, 6),  std::make_pair(15, 5)};
  ASSERT_EQ(s21_map.size(), std_map.size());
  compare_map(s21_map, std_map);
}

TEST(s21_map_case, map_default_ctor_string) {
  s21::map<int, std::string> s21_map{
      std::make_pair(15, "a"), std::make_pair(3, "b"),  std::make_pair(7, "c"),
      std::make_pair(41, "d"), std::make_pair(52, "e"), std::make_pair(6, "f")};
  std::map<int, std::string> std_map{
      std::make_pair(15, "a"), std::make_pair(3, "b"),  std::make_pair(7, "c"),
      std::make_pair(41, "d"), std::make_pair(52, "e"), std::make_pair(6, "f")};
  ASSERT_EQ(s21_map.size(), std_map.size());
  compare_map(s21_map, std_map);
  ASSERT_FALSE(s21_map.empty());
}

TEST(s21_map_case, map_copy_ctor) {
  s21::map<int, double> s21_map(
      {std::make_pair(1, 1.11), std::make_pair(3, 3.45),
       std::make_pair(7, 4.563), std::make_pair(41, 33.23),
       std::make_pair(52, 44.3), std::make_pair(67, 0.9)});
  s21::map<int, double> s21_map_copy = s21_map;
  ASSERT_EQ(s21_map_copy.size(), 6);
  ASSERT_EQ(s21_map.size(), 6);
  double map_4_check[8] = {1.11, 3.45, 4.563, 33.23, 44.3, 0.9};
  int i = 0;
  for (auto it = s21_map_copy.begin(); it != s21_map_copy.end(); ++it) {
    ASSERT_EQ(it->second, map_4_check[i]);
    i++;
  }
}

TEST(s21_map_case, map_operator_copy) {
  s21::map<int, double> s21_map;
  s21::map<int, double> s21_map_copy{std::make_pair(1, 2.5)};
  std::map<int, double> std_map{std::make_pair(1, 2.5)};

  s21_map = s21_map_copy;
  ASSERT_EQ(s21_map.size(), 1);
  compare_map(s21_map, std_map);
}

TEST(s21_map_case, map_operator_move) {
  s21::map<int, double> s21_map{std::make_pair(1, 2.5), std::make_pair(2, 3.5)};
  s21::map<int, double> s21_map_copy{std::make_pair(1, 2.5)};
  std::map<int, double> std_map{std::make_pair(1, 2.5)};

  s21_map = std::move(s21_map_copy);
  ASSERT_EQ(s21_map.size(), 1);
  compare_map(s21_map, std_map);
}

// copy move
TEST(s21_map_case, map_copy_and_move) {
  s21::map<int, int> s21_map{std::make_pair(10, 10), std::make_pair(11, 9),
                             std::make_pair(12, 8),  std::make_pair(13, 7),
                             std::make_pair(14, 6),  std::make_pair(15, 5)};
  std::map<int, int> std_map{std::make_pair(10, 10), std::make_pair(11, 9),
                             std::make_pair(12, 8),  std::make_pair(13, 7),
                             std::make_pair(14, 6),  std::make_pair(15, 5)};

  s21::map<int, int> s21_map_copy(s21_map);
  ASSERT_EQ(s21_map_copy.size(), std_map.size());
  compare_map(s21_map_copy, std_map);

  s21::map<int, int> s21_map_move(std::move(s21_map));
  ASSERT_EQ(s21_map_move.size(), std_map.size());
  compare_map(s21_map_move, std_map);
  ASSERT_TRUE(s21_map.empty());
}

TEST(s21_map_case, map_add_and_erase) {
  s21::map<int, int> s21_map{std::make_pair(10, 10)};
  s21_map.erase(s21_map.find(10));
  ASSERT_TRUE(s21_map.empty());
}

TEST(s21_map_case, erase) {
  s21::map<int, std::string> s21_map{
      std::make_pair(11, "a"), std::make_pair(32, "h"),
      std::make_pair(7, "l"),  std::make_pair(11, " "),
      std::make_pair(4, "w"),  std::make_pair(8, "l"),
      std::make_pair(52, "o"), std::make_pair(6, "e"),
      std::make_pair(5, "r"),  std::make_pair(100, "o"),
      std::make_pair(22, "l"), std::make_pair(70, "d"),
      std::make_pair(70, "d")};

  s21_map.erase(s21_map.find(100));
  s21_map.erase(s21_map.find(7));
  s21_map.erase(s21_map.find(11));
  s21_map.erase(s21_map.find(5));
  s21_map.erase(s21_map.find(32));
  s21_map.erase(s21_map.find(1));
  s21_map.erase(s21_map.find(18));
  s21_map.erase(s21_map.find(101));
  s21_map.erase(s21_map.find(4));
  s21_map.erase(s21_map.find(11));
  s21_map.erase(s21_map.find(6));

  std::map<int, std::string> std_map{
      std::make_pair(22, "l"), std::make_pair(52, "o"), std::make_pair(8, "l"),
      std::make_pair(70, "d")};
  ASSERT_EQ(s21_map.size(), std_map.size());
  ASSERT_EQ(s21_map.size(), std_map.size());
  compare_map(s21_map, std_map);
  s21_map.clear();
  ASSERT_TRUE(s21_map.empty());
}

TEST(s21_map_case, contains) {
  s21::map<int, std::string> s21_map{
      std::make_pair(15, "a"), std::make_pair(3, "h"), std::make_pair(7, "l"),
      std::make_pair(11, " ")};

  ASSERT_FALSE(s21_map.contains(100));
}

TEST(s21_map_case, insert) {
  s21::map<int, std::string> s21_map;
  s21_map.insert(std::pair<int, std::string>(10, "s"));
  s21_map.insert(std::pair<int, std::string>(50, "f"));
  s21_map.insert(std::pair<int, std::string>(20, "h"));
  s21_map.insert(std::pair<int, std::string>(70, "r"));

  auto result_insert = s21_map.insert(std::pair<int, std::string>(60, "y"));
  ASSERT_TRUE(result_insert.second);
  ASSERT_EQ((*(result_insert.first)).first, 60);
  ASSERT_EQ((*(result_insert.first)).second, "y");
  s21_map.insert(std::pair<int, std::string>(60, "y"));
  ASSERT_EQ(s21_map.size(), 5);

  std::map<int, std::string> std_map{
      std::make_pair(10, "s"), std::make_pair(50, "f"), std::make_pair(70, "r"),
      std::make_pair(20, "h"), std::make_pair(60, "y")};
  compare_map(s21_map, std_map);
  s21_map.clear();
  ASSERT_TRUE(s21_map.empty());
}

TEST(s21_map_case, insert_or_assign) {
  s21::map<int, std::string> s21_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"), std::make_pair(18, "c"),
      std::make_pair(3, "d"), std::make_pair(8, "e")};

  auto result_insert = s21_map.insert_or_assign(6, "f");
  ASSERT_TRUE(result_insert.second);
  auto result_insert1 = s21_map.insert_or_assign(3, "f");
  ASSERT_FALSE(result_insert1.second);
  ASSERT_EQ((*(result_insert1.first)).first, 3);
  ASSERT_EQ((*(result_insert1.first)).second, "f");
  ASSERT_EQ(s21_map.size(), 6);

  std::map<int, std::string> std_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"), std::make_pair(18, "c"),
      std::make_pair(3, "f"),  std::make_pair(8, "e"), std::make_pair(6, "f")};
  compare_map(s21_map, std_map);
  s21_map.clear();
  ASSERT_TRUE(s21_map.empty());
}

TEST(s21_map_case, iterator) {
  s21::map<int, std::string> s21_map{
      std::make_pair(1, "a"), std::make_pair(2, "b"), std::make_pair(3, "c")};
  auto a = s21_map.begin();
  auto a_inf_incr = ++a;
  ASSERT_EQ((*a_inf_incr).second, "b");

  auto a_post_incr = a++;
  ASSERT_EQ((*a_post_incr).second, "b");
  auto a_inf_decr = --a;

  ASSERT_EQ((*a_inf_decr).second, "b");
  ASSERT_EQ((*a).second, "b");

  auto a_post_decr = a--;
  ASSERT_EQ((*a_post_decr).second, "b");
  ASSERT_EQ((*a).second, "a");
}

TEST(s21_map_case, insert_and_erase) {
  s21::map<int, std::string> s21_map{
      std::make_pair(14, "a"), std::make_pair(4, "a"), std::make_pair(18, "a"),
      std::make_pair(3, "a"),  std::make_pair(8, "a"), std::make_pair(21, "a"),
      std::make_pair(6, "a"),  std::make_pair(11, "a")};
  s21_map.insert(5, "a");
  s21_map.insert(1, "a");
  s21_map.erase(s21_map.find(8));
  s21_map.insert(9, "a");
  s21_map.insert(10, "a");
  s21_map.insert(8, "a");
  s21_map.insert(7, "a");
  s21_map.insert(13, "a");
  s21_map.erase(s21_map.find(6));
  s21_map.erase(s21_map.find(5));
  s21_map.erase(s21_map.find(14));
  s21_map.erase(s21_map.find(13));
  std::map<int, std::string> std_map{
      std::make_pair(1, "a"),  std::make_pair(4, "a"),  std::make_pair(3, "a"),
      std::make_pair(7, "a"),  std::make_pair(8, "a"),  std::make_pair(9, "a"),
      std::make_pair(10, "a"), std::make_pair(18, "a"), std::make_pair(11, "a"),
      std::make_pair(21, "a")};

  ASSERT_EQ(s21_map.size(), std_map.size());
  compare_map(s21_map, std_map);
}

TEST(s21_map_case, at) {
  s21::map<int, std::string> s21_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"), std::make_pair(18, "c"),
      std::make_pair(3, "d"), std::make_pair(8, "e")};

  std::string a1 = s21_map.at(18);
  ASSERT_EQ(a1, "c");
  std::string a2 = s21_map.at(3);

  EXPECT_THROW(s21_map.at(100), std::out_of_range);
}

TEST(s21_map_case, access_or_insert) {
  s21::map<int, std::string> s21_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"), std::make_pair(18, "c"),
      std::make_pair(3, "d"), std::make_pair(8, "e")};

  std::map<int, std::string> std_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"), std::make_pair(18, "c"),
      std::make_pair(3, "d"),  std::make_pair(8, "e"), std::make_pair(100, "")};

  std::string a1 = s21_map.operator[](18);
  ASSERT_EQ(a1, "c");
  std::string a2 = s21_map.operator[](3);
  ASSERT_EQ(a2, "d");
  std::string a3 = s21_map.operator[](100);
  ASSERT_EQ(a3, "");
  std::string a4 = s21_map.at(100);
  ASSERT_EQ(a4, "");
  compare_map(s21_map, std_map);
}

TEST(s21_map_case, merge) {
  s21::map<int, std::string> s21_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"), std::make_pair(18, "c"),
      std::make_pair(3, "d"), std::make_pair(8, "e")};

  s21::map<int, std::string> s21_map_merge{
      std::make_pair(10, "s"),  std::make_pair(1, "b"),
      std::make_pair(18, "f"),  std::make_pair(3, "g"),
      std::make_pair(101, "g"), std::make_pair(100, "h")};

  std::map<int, std::string> std_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"),
      std::make_pair(18, "c"), std::make_pair(3, "d"),
      std::make_pair(8, "e"),  std::make_pair(10, "s"),
      std::make_pair(1, "b"),  std::make_pair(101, "g"),
      std::make_pair(100, "h")};

  s21_map.merge(s21_map_merge);
  compare_map(s21_map, std_map);
  ASSERT_EQ(s21_map.size(), std_map.size());
  ASSERT_TRUE(s21_map_merge.empty());
}

TEST(s21_map_case, insert_many) {
  s21::map<int, std::string> s21_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"), std::make_pair(18, "c"),
      std::make_pair(3, "d"), std::make_pair(8, "e")};

  std::vector<std::pair<s21::map<int, std::string>::iterator, bool>> res =
      s21_map.insert_many(std::make_pair(10, "s"), std::make_pair(1, "b"),
                          std::make_pair(18, "f"), std::make_pair(3, "g"),
                          std::make_pair(101, "g"), std::make_pair(100, "h"));

  std::map<int, std::string> std_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"),
      std::make_pair(18, "c"), std::make_pair(3, "d"),
      std::make_pair(8, "e"),  std::make_pair(10, "s"),
      std::make_pair(1, "b"),  std::make_pair(101, "g"),
      std::make_pair(100, "h")};

  compare_map(s21_map, std_map);
  ASSERT_EQ(s21_map.size(), std_map.size());

  // for (auto item : res) {
  //     std::cout << item.first->second << std::endl;
  // }
}