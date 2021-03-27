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
    explicit BinaryOperatorExpression(IdentifierExpression *lhs, int op, IdentifierExpression *rhs)
        : lhs_(lhs), rhs_(rhs), op_(op)
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    int op_;
    IdentifierExpression *lhs_;
    IdentifierExpression *rhs_;
};
} // namespace Parser::AST