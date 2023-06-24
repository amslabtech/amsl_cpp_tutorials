cmake_minimum_required(VERSION 3.16.3)

project(02_include)

# インクルードディレクトリを指定
include_directories(../common)

add_executable(main main.cpp)
