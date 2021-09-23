cmake_minimum_required(VERSION 3.20)
project(blockchain_sj_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(blockchain_sj_cpp main.cpp Block.cpp Block.h picosha2.h)
