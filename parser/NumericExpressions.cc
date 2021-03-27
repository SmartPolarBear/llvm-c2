#include "NumericExpressions.h"

using namespace Parser::AST;
using namespace llvm;

llvm::Value *IntegralExpression::codegen()
{
    return nullptr;
}

llvm::Value *DoubleExpression::codegen()
{
    return nullptr;
}

llvm::Value *UnsignedExpression::codegen()
{
    return nullptr;
}