#include "Program.h"
#include "NumericExpressions.h"

#include <llvm/IR/Constants.h>

using namespace Parser::AST;
using namespace llvm;

llvm::Value *IntegralExpression::codegen()
{
    return ConstantInt::get(*Program::Instance().Context(), APInt(64, value_, true));
}

llvm::Value *DoubleExpression::codegen()
{
    return ConstantFP::get(*Program::Instance().Context(), APFloat{value_});
}

llvm::Value *UnsignedExpression::codegen()
{
    return ConstantInt::get(*Program::Instance().Context(), APInt(64, value_, false));
}