#pragma once

#include "Node.h"
#include "IdentifierExpression.h"

#include <cstdint>
#include <string>

namespace Parser::AST
{
class BinaryOperatorExpression : public ExpressionNode
{
  public:
    explicit BinaryOperatorExpression(ExpressionNode *lhs, int op, ExpressionNode *rhs)
        : lhs_(lhs), rhs_(rhs), op_(op)
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    int op_;
    ExpressionNode *lhs_;
    ExpressionNode *rhs_;
};
} // namespace Parser::AST