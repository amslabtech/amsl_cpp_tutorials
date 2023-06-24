project(03_multiple_sources)

cmake_minimum_required(VERSION 3.16.3)

include_directories(../common)

# 更新のあったソースファイルだけコンパイルされる
add_executable(main main.cpp lib.cpp)
