#pragma once

#include "Node.h"

#include <cstdint>

namespace Parser::AST
{
class IntegralExpression : public ExpressionNode
{
  public:
    explicit IntegralExpression(int64_t val) : value_(val)
    {
        
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    int64_t value_;
};

class DoubleExpression : public ExpressionNode
{
  public:
    explicit DoubleExpression(long double val) : value_(val)
    {
        
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    long double value_;
};

class UnsignedExpression : public ExpressionNode
{
  public:
    explicit UnsignedExpression(uint64_t val) : value_(val)
    {
        
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    uint64_t value_;
};
} // namespace Parser::AST