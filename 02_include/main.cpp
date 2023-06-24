// Copyright 2023 AMSL

#include <iostream>

// includeは、指定したファイルの内容をその場に展開する
// 参考: https://learn.microsoft.com/ja-jp/cpp/preprocessor/hash-include-directive-c-cpp?view=msvc-170
#include <include/sample_header.h>

// sample_header.h内のインクルードガードがあるので、二回インクルードしてもエラーにならない
// インクルードガードを削除するとニ重定義エラーが起きる
// #include <include/sample_header.h>

int main(int argc, char **argv)
{
  // sample_header.hで宣言した関数を呼び出す
  common::print_hello_world();
  return 0;
}
