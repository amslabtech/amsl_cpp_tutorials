cmake_minimum_required(VERSION 3.16.3)

project(10_thread)

find_package(Threads REQUIRED)
set(CMAKE_USE_PTHREADS_INIT ON)

add_executable(main main.cpp)

target_link_libraries(main Threads::Threads)
