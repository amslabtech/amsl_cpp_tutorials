// Copyright 2023 AMSL

#include <iostream>

// 同ディレクトリ以下のパスの指定は""で囲む
#include "lib.h"

namespace lib
{
  // 実装
  void print_hello_world()
  {
    std::cout << "Hello, world! from " << __FILE__ << std::endl;

  }
}
