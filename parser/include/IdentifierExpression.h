#pragma once

#include "Node.h"
#include <cstdint>
#include <string>

namespace Parser::AST
{
class IdentifierExpression : public ExpressionNode
{
  public:
    explicit IdentifierExpression(const std::string &name) : name_(name)
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    std::string name_;
};
} // namespace Parser::AST