cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project(llvm-basic)

add_executable(basic)

add_subdirectory(parser)
add_subdirectory(scanner)

target_sources(basic PRIVATE main.cc)