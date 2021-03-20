#pragma once

#include "Node.h"
#include <cstdint>
#include <string>

namespace Parser::AST
{
class VariableExpression : public Node
{
  public:
    explicit VariableExpression(std::string &&str) : name_(std::move(str))
    {
    }

    [[nodiscard]] llvm::Value *codegen() override;

  private:
    std::string name_{""};
};

} // namespace Parser::AST