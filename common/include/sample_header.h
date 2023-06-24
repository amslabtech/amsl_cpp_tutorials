// Copyright 2023 AMSL

// インクルードガード
#ifndef SAMPLE_HEADER_H
// define行をコメントアウトするとインクルードガードを無効化できる
#define SAMPLE_HEADER_H

#include <iostream>

// common名前空間
namespace common
{
  // 関数の宣言と定義
  void print_hello_world()
  {
    std::cout << "Hello, world! from " << __FILE__ << std::endl;
  }
}

#endif // SAMPLE_HEADER_H
