#include "BinaryOperatorExpression.h"

using namespace Parser::AST;
using namespace llvm;

llvm::Value *BinaryOperatorExpression::codegen()
{
    auto lhs = lhs_->codegen(), rhs = rhs_->codegen();
    if (!lhs || !rhs)
    {
        return nullptr;
    }

    
    return nullptr;
}