cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

target_sources(basic 
    PRIVATE Parser.cc
    PRIVATE Block.cc
    PRIVATE IntegralExpression.cc
    PRIVATE IdentifierExpression.cc
    PRIVATE ExpressionStatement.cc
    PRIVATE FunctionDeclarationStatement.cc
    PRIVATE VariableDeclarationStatement.cc)

target_include_directories(basic
    PRIVATE include)