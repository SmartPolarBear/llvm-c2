cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project(llvm-basic)

add_executable(basic)

target_sources(basic PRIVATE main.cc)