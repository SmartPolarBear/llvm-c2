cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(llvm-basic)

set(CXX_STANDARD 20)


find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

FLEX_TARGET(Scanner scanner/Scanner.l ${CMAKE_CURRENT_BINARY_DIR}/Scanner.cc)
BISON_TARGET(Parser parser/Parser.y ${CMAKE_CURRENT_BINARY_DIR}/Parser.cc)

ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

llvm_map_components_to_libnames(llvm_libs support core irreader)

add_executable(basic
        Main.cc
        Program.cc
        ${BISON_Parser_OUTPUTS}
        ${FLEX_Scanner_OUTPUTS})

set_property(TARGET basic PROPERTY CXX_STANDARD 20)

add_subdirectory(parser)
add_subdirectory(scanner)

target_include_directories(basic 
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${LLVM_INCLUDE_DIRS}
        PUBLIC include)


target_compile_definitions(basic
        PUBLIC ${LLVM_DEFINITIONS})

target_link_libraries(basic
        PUBLIC ${llvm_libs})

target_link_options(basic 
        PRIVATE -lc++)
