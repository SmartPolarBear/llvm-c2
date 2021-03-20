cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(llvm-basic)

set(CXX_STANDARD_REQUIRED 20)


find_package(BISON)
find_package(FLEX)

FLEX_TARGET(Scanner scanner/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc)
BISON_TARGET(Parser parser/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)

ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

add_executable(basic
        main.cc
        ${BISON_Parser_OUTPUTS}
        ${FLEX_Scanner_OUTPUTS})

add_subdirectory(parser)
add_subdirectory(scanner)

target_include_directories(basic PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
