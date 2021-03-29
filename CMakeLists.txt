cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(llvm-safec)

set(CXX_STANDARD 20)


find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

FLEX_TARGET(Scanner scanner/Scanner.l 
        ${CMAKE_CURRENT_BINARY_DIR}/Scanner.cc 
        )

BISON_TARGET(Parser parser/Parser.y 
        ${CMAKE_CURRENT_BINARY_DIR}/Parser.cc 
        VERBOSE ${CMAKE_CURRENT_BINARY_DIR}/Parser.txt
        COMPILE_FLAGS "-Wcounterexamples")

ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

llvm_map_components_to_libnames(llvm_libs support core irreader)

add_executable(safec
        Main.cc
        Program.cc
        ${BISON_Parser_OUTPUTS}
        ${FLEX_Scanner_OUTPUTS})

set_property(TARGET safec PROPERTY CXX_STANDARD 20)

add_subdirectory(external)

add_subdirectory(parser)
add_subdirectory(scanner)
add_subdirectory(cli)

target_include_directories(safec 
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${LLVM_INCLUDE_DIRS}
        PUBLIC include)


target_compile_definitions(safec
        PUBLIC ${LLVM_DEFINITIONS})

target_link_libraries(safec
        PUBLIC ${llvm_libs})

target_link_options(safec 
        PRIVATE -lc++)
