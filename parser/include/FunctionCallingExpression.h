#pragma once

#include "Node.h"
#include "IdentifierExpression.h"

#include <cstdint>
#include <vector>

namespace Parser::AST
{
class FunctionCallingExpression : public ExpressionNode
{
  public:
    using ArgListType = std::vector<ExpressionNode *>;

  public:
    explicit FunctionCallingExpression(IdentifierExpression *func) : func_(func), arglist_()
    {
    }

    explicit FunctionCallingExpression(IdentifierExpression *func, ArgListType &&args)
        : func_(func), arglist_(args)
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    const IdentifierExpression *func_;
    mutable ArgListType arglist_;
};
} // namespace Parser::AST