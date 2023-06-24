project(02_include)

cmake_minimum_required(VERSION 3.16.3)

# インクルードディレクトリを指定
include_directories(../common)

add_executable(main main.cpp)
