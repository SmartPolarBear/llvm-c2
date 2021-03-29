cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

include(ExternalProject)

list(APPEND FMTLIB_CMAKE_ARGS
        -DBUILD_SHARED_LIBS=TRUE
        )

ExternalProject_Add(
        fmtlib_build
        PREFIX ${INSTALL_PREFIX}
        SOURCE_DIR ${FMTLIB_SRC_DIR}
        CMAKE_ARGS ${FMTLIB_CMAKE_ARGS}
)

