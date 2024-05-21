// Copyright 2024 AMSL

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  // templateで型を指定する
  std::vector<int> v;
  // push_backで要素を追加
  v.push_back(1);
  std::cout << "vの要素数: " << v.size() << std::endl;
  v.push_back(2);
  std::cout << "vの要素数: " << v.size() << std::endl;
  // 添字またはatで要素にアクセス
  std::cout << "v[0]: " << v[0] << std::endl;
  std::cout << "v.at(1): " << v.at(1) << std::endl;
  try
  {
    std::cout << "v[2]: " << v.at(2) << std::endl;
  }
  catch (std::out_of_range &e)
  {
    std::cout << "範囲外アクセスによる例外: " << e.what() << std::endl;
  }
  std::cout << "vの容量: " << v.capacity() << std::endl;
  // 容量の確保(要素数は変わらない)
  // reserve()の挙動について参考: https://cpprefjp.github.io/reference/vector/vector/reserve.html
  v.reserve(10);
  std::cout << "vの要素数: " << v.size() << std::endl;
  std::cout << "vの容量: " << v.capacity() << std::endl;
  // 要素数変更
  // 3番目以降の要素は初期化される
  v.resize(10);
  std::cout << "vの要素数: " << v.size() << std::endl;

  {
    // vの先頭要素を指すイテレータ
    std::vector<int>::iterator it = v.begin();
    // auto it = v.begin(); のように書くことが多い

    std::cout << "要素を全てループして出力" << std::endl;
    for (; it != v.end(); it++)
    {
      std::cout << "v[" << it - v.begin() << "]: " << *it << std::endl;
    }
  }

  std::cout << "範囲ベースfor" << std::endl;
  // eはvの要素への参照
  for (auto &e : v)
  {
    std::cout << "v[" << &e - &v[0] << "]: " << e << std::endl;
  }

  // ループしながら条件を満たす要素を削除
  for (auto it = v.begin(); it != v.end();)
  {
    // 要素が0なら削除
    if (*it == 0)
    {
      it = v.erase(it);
    }
    else
    {
      it++;
    }
  }
  std::cout << "削除後のvの要素数: " << v.size() << std::endl;
  for (auto &e : v)
  {
    std::cout << "v[" << &e - &v[0] << "]: " << e << std::endl;
  }
  std::cout << "v.empty(): " << (v.empty() ? "true" : "false") << std::endl;
  std::cout << "要素を全て削除" << std::endl;
  v.clear();
  std::cout << "vの要素数: " << v.size() << std::endl;
  std::cout << "v.empty(): " << (v.empty() ? "true" : "false") << std::endl;

  // 2行3列の2次元配列
  std::vector<std::vector<int>> v2{
      {1, 2, 3},
      {4, 5, 6},
  };
  for (auto &e1 : v2)
  {
    for (auto &e2 : e1)
    {
      std::cout << e2 << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
