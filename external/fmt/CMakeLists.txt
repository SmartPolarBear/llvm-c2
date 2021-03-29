cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

add_subdirectory(fmt)

target_link_directories(safec PRIVATE fmt::fmt-header-only)
