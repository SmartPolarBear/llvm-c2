cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

target_sources(basic 
    PRIVATE Parser.cc
    PRIVATE IntegralExpression.cc
    PRIVATE VariableExpression.cc)

target_include_directories(basic
    PRIVATE include)