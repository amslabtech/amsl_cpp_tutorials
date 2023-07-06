cmake_minimum_required(VERSION 3.16.3)

project(04_static_library)

# 参考: https://cmake.org/cmake/help/latest/command/add_library.html
# 静的ライブラリの作成
# この場合libstatic_sample.a という名前で作成される
add_library(static_sample STATIC lib.cpp)

add_executable(main main.cpp)
target_link_libraries(main static_sample)
