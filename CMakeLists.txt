cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(llvm-basic)

find_package(BISON)
find_package(FLEX)

FLEX_TARGET(Scanner scanner/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc)
BISON_TARGET(Parser parser/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)

ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

add_executable(basic
        main.cc
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS})
