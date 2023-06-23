# プロジェクト名
project(01_hello_world)

# CMakeのバージョン。もっと古くても良いが、Ubuntu20.04のデフォルトのバージョンとした
cmake_minimum_required(VERSION 3.16.3)

# 生成する実行ファイル名とソースファイル名を指定
add_executable(main main.cpp)
