cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

set(INSTALL_PREFIX  ${CMAKE_BINARY_DIR}/external/third_party_root)

set(FMTLIB_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/fmt/fmt)

add_subdirectory(fmt)