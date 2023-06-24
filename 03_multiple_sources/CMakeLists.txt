cmake_minimum_required(VERSION 3.16.3)

project(03_multiple_sources)

include_directories(../common)

# 更新のあったソースファイルだけコンパイルされる
add_executable(main main.cpp lib.cpp)
