cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

target_sources(basic 
    PRIVATE Parser.cc
    PRIVATE Block.cc
    PRIVATE NumericExpressions.cc
    PRIVATE IdentifierExpression.cc
    PRIVATE AssignmentExpression.cc
    PRIVATE ExpressionStatement.cc
    PRIVATE BinaryOperatorExpression.cc
    PRIVATE FunctionCallingExpression.cc
    PRIVATE FunctionDeclarationStatement.cc
    PRIVATE VariableDeclarationStatement.cc)

target_include_directories(basic
    PRIVATE include)