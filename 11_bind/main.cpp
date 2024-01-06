// Copyright 2024 AMSL

#include <iostream>
#include <functional>

// 引数を3つ受け取る関数
void func(int a, int b, int c)
{
  std::cout << a << " " << b << " " << c << std::endl;
}

class Hoge
{
public:
  void func(int a, int b, int c)
  {
    std::cout << a << " " << b << " " << c << std::endl;
  }

  void func2()
  {
    // メンバ関数の場合はthisを指定する必要がある
    std::function<void(int, int)> f = std::bind(&Hoge::func, this, std::placeholders::_1, std::placeholders::_2, 30);
    f(10, 20);
  }
};

int main(int argc, char **argv)
{
  {
    // funcの第3引数を30にし、引数を2つ受け取る関数オブジェクトfを作成
    std::function<void(int, int)> f = std::bind(func, std::placeholders::_1, std::placeholders::_2, 30);
    // 10 20 30と出力される
    f(10, 20);
    // 引数の順番を入れ替えることも可能
    f = std::bind(func, std::placeholders::_2, 30, std::placeholders::_1);
    // 20 30 10と出力される
    f(10, 20);
    // placeholdersを一つにする場合
    std::function<void(int)> f2 = std::bind(func, std::placeholders::_1, 20, 30);
    // 10 20 30と出力される
    f2(10);
  }

  {
    // メンバ関数の場合
    Hoge h;
    // 対象インスタンスのアドレスも必要
    std::function<void(int, int)> f = std::bind(&Hoge::func, &h, std::placeholders::_1, std::placeholders::_2, 30);
    // 10 20 30と出力される
    f(10, 20);
  }

  {
    // メンバ関数内で別のメンバ関数をbindする場合
    Hoge h;
    // 10 20 30と出力される
    h.func2();
  }
  return 0;
}
