#pragma once

#include "Node.h"
#include <cstdint>

namespace Parser::AST
{
class IntegralExpression : public Node
{
  public:
    explicit IntegralExpression(int64_t val) : value_(val)
    {
        
    }

    [[nodiscard]] llvm::Value *codegen() override;

  private:
    int64_t value_;
};
} // namespace Parser::AST