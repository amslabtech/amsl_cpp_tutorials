// Copyright 2024 AMSL

#include <iostream>
#include <optional>

int main(int argc, char **argv)
{
  std::optional<int> num;
  if (!num.has_value())
  {
    std::cout << "値が含まれていません。" << std::endl;
  }
  // 値が含まれていないので値の取得もできない
  try
  {
    std::cout << num.value() << std::endl;
  }
  catch (std::bad_optional_access &e)
  {
    std::cout << "例外: " << e.what() << std::endl;
  }

  num = 1;
  if (num.has_value())
  {
    std::cout << "値が含まれています。値: " << num.value() << std::endl;
  }

  num.reset();
  if (!num.has_value())
  {
    std::cout << "値が含まれていません。" << std::endl;
  }

  // std::optionalではstd::nulloptを無効値として扱う
  num = std::nullopt; // std::nulloptを使ってリセット
  if (!num.has_value())
  {
    std::cout << "有効値が含まれていません。" << std::endl;
  }
  return 0;
}
