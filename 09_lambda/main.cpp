// Copyright 2023 AMSL

#include <iostream>
#include <functional>

// 普通の関数オブジェクト
struct Func
{
  void operator()() const
  {
    std::cout << "Hello, Func!" << std::endl;
  }
};

int main(int argc, char **argv)
{
  {
    // 関数オブジェクトの呼び出し
    Func func;
    func();
  }
  {
    // これも可
    std::function<void()> func = Func();
    func();
  }
  {
    // autoでも良い
    auto func = Func();
    func();
  }
  {
    // lambda
    // 特に理由が無ければautoで受ける
    auto func = []() {
      std::cout << "Hello, Lambda!" << std::endl;
    };
    func();
  }
  {
    // 引数を取る例
    auto func = [](const std::string& str) {
      std::cout << "Hello, " << str << "!" << std::endl;
    };
    func("Lambda");
  }
  {
    // キャプチャ(コピー)
    std::string str = "Lambda";
    auto func = [str]() {
      std::cout << "Hello, " << str << "!" << std::endl;
    };
    func();
  }
  {
    // キャプチャ(参照)
    std::string str = "Lambda";
    auto func = [&str]() {
      str = "Lambda2";
      std::cout << "Hello, " << str << "!" << std::endl;
      str = "Lambda3";
    };
    std::cout << "str is " << str << std::endl;
    func();
    std::cout << "str is " << str << std::endl;
  }
}
