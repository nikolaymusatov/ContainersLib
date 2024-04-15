#include <map>

#include "test.h"

using namespace MyNamespace;

template <typename Key, typename T>
void compare_map(Map<Key, T> &Map, std::map<Key, T> &std_map) {
  auto i = Map.begin();
  auto std_i = std_map.begin();
  while (i != Map.end() || std_i != std_map.end()) {
    ASSERT_EQ(i->first, std_i->first);
    ASSERT_EQ(i->second, std_i->second);
    ++i;
    ++std_i;
  }
}

TEST(map_case, is_empty) {
  // default
  Map<int, int> Map;
  std::map<int, int> std_map;
  ASSERT_EQ(Map.empty(), std_map.empty());
}

TEST(map_case, map_default_ctor) {
  Map<int, int> Map{std::make_pair(10, 10), std::make_pair(11, 9),
                    std::make_pair(12, 8),  std::make_pair(13, 7),
                    std::make_pair(14, 6),  std::make_pair(15, 5)};
  std::map<int, int> std_map{std::make_pair(10, 10), std::make_pair(11, 9),
                             std::make_pair(12, 8),  std::make_pair(13, 7),
                             std::make_pair(14, 6),  std::make_pair(15, 5)};
  ASSERT_EQ(Map.size(), std_map.size());
  compare_map(Map, std_map);
}

TEST(map_case, map_default_ctor_string) {
  Map<int, std::string> map{std::make_pair(15, "a"), std::make_pair(3, "b"),
                            std::make_pair(7, "c"),  std::make_pair(41, "d"),
                            std::make_pair(52, "e"), std::make_pair(6, "f")};
  std::map<int, std::string> std_map{
      std::make_pair(15, "a"), std::make_pair(3, "b"),  std::make_pair(7, "c"),
      std::make_pair(41, "d"), std::make_pair(52, "e"), std::make_pair(6, "f")};
  ASSERT_EQ(map.size(), std_map.size());
  compare_map(map, std_map);
  ASSERT_FALSE(map.empty());
}

TEST(map_case, map_copy_ctor) {
  Map<int, double> map({std::make_pair(1, 1.11), std::make_pair(3, 3.45),
                        std::make_pair(7, 4.563), std::make_pair(41, 33.23),
                        std::make_pair(52, 44.3), std::make_pair(67, 0.9)});
  Map<int, double> map_copy = map;
  ASSERT_EQ(map_copy.size(), 6);
  ASSERT_EQ(map.size(), 6);
  double map_4_check[8] = {1.11, 3.45, 4.563, 33.23, 44.3, 0.9};
  int i = 0;
  for (auto it = map_copy.begin(); it != map_copy.end(); ++it) {
    ASSERT_EQ(it->second, map_4_check[i]);
    i++;
  }
}

TEST(map_case, map_operator_copy) {
  Map<int, double> map;
  Map<int, double> map_copy{std::make_pair(1, 2.5)};
  std::map<int, double> std_map{std::make_pair(1, 2.5)};

  map = map_copy;
  ASSERT_EQ(map.size(), 1);
  compare_map(map, std_map);
}

TEST(map_case, map_operator_move) {
  Map<int, double> map{std::make_pair(1, 2.5), std::make_pair(2, 3.5)};
  Map<int, double> map_copy{std::make_pair(1, 2.5)};
  std::map<int, double> std_map{std::make_pair(1, 2.5)};

  map = std::move(map_copy);
  ASSERT_EQ(map.size(), 1);
  compare_map(map, std_map);
}

// copy move
TEST(map_case, map_copy_and_move) {
  Map<int, int> map{std::make_pair(10, 10), std::make_pair(11, 9),
                    std::make_pair(12, 8),  std::make_pair(13, 7),
                    std::make_pair(14, 6),  std::make_pair(15, 5)};
  std::map<int, int> std_map{std::make_pair(10, 10), std::make_pair(11, 9),
                             std::make_pair(12, 8),  std::make_pair(13, 7),
                             std::make_pair(14, 6),  std::make_pair(15, 5)};

  Map<int, int> map_copy(map);
  ASSERT_EQ(map_copy.size(), std_map.size());
  compare_map(map_copy, std_map);

  Map<int, int> map_move(std::move(map));
  ASSERT_EQ(map_move.size(), std_map.size());
  compare_map(map_move, std_map);
  ASSERT_TRUE(map.empty());
}

TEST(map_case, map_add_and_erase) {
  Map<int, int> Map{std::make_pair(10, 10)};
  Map.erase(Map.find(10));
  ASSERT_TRUE(Map.empty());
}

TEST(map_case, erase) {
  Map<int, std::string> Map{std::make_pair(11, "a"), std::make_pair(32, "h"),
                            std::make_pair(7, "l"),  std::make_pair(11, " "),
                            std::make_pair(4, "w"),  std::make_pair(8, "l"),
                            std::make_pair(52, "o"), std::make_pair(6, "e"),
                            std::make_pair(5, "r"),  std::make_pair(100, "o"),
                            std::make_pair(22, "l"), std::make_pair(70, "d"),
                            std::make_pair(70, "d")};

  Map.erase(Map.find(100));
  Map.erase(Map.find(7));
  Map.erase(Map.find(11));
  Map.erase(Map.find(5));
  Map.erase(Map.find(32));
  Map.erase(Map.find(1));
  Map.erase(Map.find(18));
  Map.erase(Map.find(101));
  Map.erase(Map.find(4));
  Map.erase(Map.find(11));
  Map.erase(Map.find(6));

  std::map<int, std::string> std_map{
      std::make_pair(22, "l"), std::make_pair(52, "o"), std::make_pair(8, "l"),
      std::make_pair(70, "d")};
  ASSERT_EQ(Map.size(), std_map.size());
  ASSERT_EQ(Map.size(), std_map.size());
  compare_map(Map, std_map);
  Map.clear();
  ASSERT_TRUE(Map.empty());
}

TEST(map_case, contains) {
  Map<int, std::string> Map{std::make_pair(15, "a"), std::make_pair(3, "h"),
                            std::make_pair(7, "l"), std::make_pair(11, " ")};

  ASSERT_FALSE(Map.contains(100));
}

TEST(map_case, insert) {
  Map<int, std::string> Map;
  Map.insert(std::pair<int, std::string>(10, "s"));
  Map.insert(std::pair<int, std::string>(50, "f"));
  Map.insert(std::pair<int, std::string>(20, "h"));
  Map.insert(std::pair<int, std::string>(70, "r"));

  auto result_insert = Map.insert(std::pair<int, std::string>(60, "y"));
  ASSERT_TRUE(result_insert.second);
  ASSERT_EQ((*(result_insert.first)).first, 60);
  ASSERT_EQ((*(result_insert.first)).second, "y");
  Map.insert(std::pair<int, std::string>(60, "y"));
  ASSERT_EQ(Map.size(), 5);

  std::map<int, std::string> std_map{
      std::make_pair(10, "s"), std::make_pair(50, "f"), std::make_pair(70, "r"),
      std::make_pair(20, "h"), std::make_pair(60, "y")};
  compare_map(Map, std_map);
  Map.clear();
  ASSERT_TRUE(Map.empty());
}

TEST(map_case, insert_or_assign) {
  Map<int, std::string> Map{std::make_pair(14, "a"), std::make_pair(4, "b"),
                            std::make_pair(18, "c"), std::make_pair(3, "d"),
                            std::make_pair(8, "e")};

  auto result_insert = Map.insert_or_assign(6, "f");
  ASSERT_TRUE(result_insert.second);
  auto result_insert1 = Map.insert_or_assign(3, "f");
  ASSERT_FALSE(result_insert1.second);
  ASSERT_EQ((*(result_insert1.first)).first, 3);
  ASSERT_EQ((*(result_insert1.first)).second, "f");
  ASSERT_EQ(Map.size(), 6);

  std::map<int, std::string> std_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"), std::make_pair(18, "c"),
      std::make_pair(3, "f"),  std::make_pair(8, "e"), std::make_pair(6, "f")};
  compare_map(Map, std_map);
  Map.clear();
  ASSERT_TRUE(Map.empty());
}

TEST(map_case, iterator) {
  Map<int, std::string> Map{std::make_pair(1, "a"), std::make_pair(2, "b"),
                            std::make_pair(3, "c")};
  auto a = Map.begin();
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

TEST(map_case, insert_and_erase) {
  Map<int, std::string> Map{std::make_pair(14, "a"), std::make_pair(4, "a"),
                            std::make_pair(18, "a"), std::make_pair(3, "a"),
                            std::make_pair(8, "a"),  std::make_pair(21, "a"),
                            std::make_pair(6, "a"),  std::make_pair(11, "a")};
  Map.insert(5, "a");
  Map.insert(1, "a");
  Map.erase(Map.find(8));
  Map.insert(9, "a");
  Map.insert(10, "a");
  Map.insert(8, "a");
  Map.insert(7, "a");
  Map.insert(13, "a");
  Map.erase(Map.find(6));
  Map.erase(Map.find(5));
  Map.erase(Map.find(14));
  Map.erase(Map.find(13));
  std::map<int, std::string> std_map{
      std::make_pair(1, "a"),  std::make_pair(4, "a"),  std::make_pair(3, "a"),
      std::make_pair(7, "a"),  std::make_pair(8, "a"),  std::make_pair(9, "a"),
      std::make_pair(10, "a"), std::make_pair(18, "a"), std::make_pair(11, "a"),
      std::make_pair(21, "a")};

  ASSERT_EQ(Map.size(), std_map.size());
  compare_map(Map, std_map);
}

TEST(map_case, at) {
  Map<int, std::string> Map{std::make_pair(14, "a"), std::make_pair(4, "b"),
                            std::make_pair(18, "c"), std::make_pair(3, "d"),
                            std::make_pair(8, "e")};

  std::string a1 = Map.at(18);
  ASSERT_EQ(a1, "c");
  std::string a2 = Map.at(3);

  EXPECT_THROW(Map.at(100), std::out_of_range);
}

TEST(map_case, access_or_insert) {
  Map<int, std::string> Map{std::make_pair(14, "a"), std::make_pair(4, "b"),
                            std::make_pair(18, "c"), std::make_pair(3, "d"),
                            std::make_pair(8, "e")};

  std::map<int, std::string> std_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"), std::make_pair(18, "c"),
      std::make_pair(3, "d"),  std::make_pair(8, "e"), std::make_pair(100, "")};

  std::string a1 = Map.operator[](18);
  ASSERT_EQ(a1, "c");
  std::string a2 = Map.operator[](3);
  ASSERT_EQ(a2, "d");
  std::string a3 = Map.operator[](100);
  ASSERT_EQ(a3, "");
  std::string a4 = Map.at(100);
  ASSERT_EQ(a4, "");
  compare_map(Map, std_map);
}

TEST(map_case, merge) {
  Map<int, std::string> map{std::make_pair(14, "a"), std::make_pair(4, "b"),
                            std::make_pair(18, "c"), std::make_pair(3, "d"),
                            std::make_pair(8, "e")};

  Map<int, std::string> map_merge{
      std::make_pair(10, "s"),  std::make_pair(1, "b"),
      std::make_pair(18, "f"),  std::make_pair(3, "g"),
      std::make_pair(101, "g"), std::make_pair(100, "h")};

  std::map<int, std::string> std_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"),
      std::make_pair(18, "c"), std::make_pair(3, "d"),
      std::make_pair(8, "e"),  std::make_pair(10, "s"),
      std::make_pair(1, "b"),  std::make_pair(101, "g"),
      std::make_pair(100, "h")};

  map.merge(map_merge);
  compare_map(map, std_map);
  ASSERT_EQ(map.size(), std_map.size());
  ASSERT_TRUE(map_merge.empty());
}

TEST(map_case, insert_many) {
  Map<int, std::string> map{std::make_pair(14, "a"), std::make_pair(4, "b"),
                            std::make_pair(18, "c"), std::make_pair(3, "d"),
                            std::make_pair(8, "e")};

  std::vector<std::pair<Map<int, std::string>::iterator, bool>> res =
      map.insert_many(std::make_pair(10, "s"), std::make_pair(1, "b"),
                      std::make_pair(18, "f"), std::make_pair(3, "g"),
                      std::make_pair(101, "g"), std::make_pair(100, "h"));

  std::map<int, std::string> std_map{
      std::make_pair(14, "a"), std::make_pair(4, "b"),
      std::make_pair(18, "c"), std::make_pair(3, "d"),
      std::make_pair(8, "e"),  std::make_pair(10, "s"),
      std::make_pair(1, "b"),  std::make_pair(101, "g"),
      std::make_pair(100, "h")};

  compare_map(map, std_map);
  ASSERT_EQ(map.size(), std_map.size());
}