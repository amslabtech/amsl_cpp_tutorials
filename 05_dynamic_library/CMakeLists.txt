cmake_minimum_required(VERSION 3.16.3)

project(05_dynamic_library)

# 参考: https://cmake.org/cmake/help/latest/command/add_library.html
# 動的ライブラリの作成
# この場合libdynamic_sample.so という名前で作成される
add_library(dynamic_sample SHARED lib.cpp)

add_executable(main main.cpp)
target_link_libraries(main dynamic_sample)
