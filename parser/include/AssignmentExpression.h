#pragma once

#include "Node.h"
#include "IdentifierExpression.h"

#include <cstdint>

namespace Parser::AST
{
class AssignmentExpression : public ExpressionNode
{
  public:
    explicit AssignmentExpression(IdentifierExpression *lhs, ExpressionNode *rhs) : lhs_(lhs), rhs_(rhs)
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    IdentifierExpression *lhs_;
    ExpressionNode *rhs_;
};
} // namespace Parser::AST