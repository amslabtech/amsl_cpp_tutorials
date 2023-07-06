// Copyright 2023 AMSL

// iostream: Input-Output stream
// C++の標準入出力ライブラリ
#include <iostream>

int main(int argc, char **argv)
{
  // ::はスコープ解決演算子と呼ぶ
  // - https://learn.microsoft.com/ja-jp/cpp/cpp/scope-resolution-operator?view=msvc-170
  // std::cout: 標準出力ストリーム
  // - https://cpprefjp.github.io/reference/iostream/cout.html
  // std::endl: 改行
  // - https://cpprefjp.github.io/reference/ostream/endl.html
  // <<: 本来左シフト演算子だが、ここでは挿入演算子と呼ぶ
  // - https://docs.oracle.com/cd/E19957-01/805-7889/z4000016dc5a6/index.html
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
