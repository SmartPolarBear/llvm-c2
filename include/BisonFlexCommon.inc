#pragma once

#ifndef BISONLEXFILE
#error "This must be included by .y or .l file"
#endif

#include <cstdio>
#include <cstdint>

#include <iostream>
#include <string_view>
#include <memory>

#include "Types.h"

#include "Program.h"

#include "Node.h"
#include "Block.h"
#include "ExpressionStatement.h"
#include "IdentifierExpression.h"
#include "NumericExpressions.h"
#include "AssignmentExpression.h"
#include "BinaryOperatorExpression.h"
#include "VariableDeclarationStatement.h" 
#include "FunctionDeclarationStatement.h"
#include "FunctionCallingExpression.h"

using namespace std;

using namespace llvm;
using namespace Parser::AST;

extern "C" int yylex();
extern "C" int yyparse();