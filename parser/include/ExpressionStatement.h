#pragma once

#include "Node.h"
#include <cstdint>

namespace Parser::AST
{
class ExpressionStatement : public StatementNode
{
  public:
    explicit ExpressionStatement(ExpressionNode *expr) : expr_(expr)
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    ExpressionNode *expr_;
};
} // namespace Parser::AST