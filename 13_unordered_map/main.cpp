// Copyright 2024 AMSL

#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char **argv)
{
  std::unordered_map<std::string, int> um;
  um["abc"] = 1;
  um["def"] = 2;
  um["ghi"] = 3;
  std::cout << "要素数: " << um.size() << std::endl;
  for (const auto &e : um)
  {
    // 各要素はstd::pair
    // firstがkey, secondがvalueに相当する
    std::cout << e.first << ": " << e.second << std::endl;
  }
  // keyの検索
  if (um.find("abc") != um.end())
  {
    std::cout << "abcはkeyに含まれます。値: " << um.at("abc") << std::endl;
  }
  if (um.find("jkf") == um.end())
  {
    // 存在しないkeyを[]で指定すると勝手に要素が追加される。それを避けるためにはat()を使う
    try
    {
      std::cout << "jkfはkeyに含まれません。値: " << um.at("jkf") << std::endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << "例外: " << e.what() << '\n';
    }
    // []を使った場合例外が投げられない
    std::cout << "jkfはkeyに含まれません。値: " << um["jkf"] << std::endl;
  }
  return 0;
}
