#pragma once

#include "Node.h"

#include <cstdint>

namespace Parser::AST
{
class IntegralExpression : public ExpressionNode
{
  public:
    using IntegralType = int64_t;

    explicit IntegralExpression(IntegralType val) : value_(val)
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    IntegralType value_;
};

class DoubleExpression : public ExpressionNode
{
  public:
    using DoubleType = double;

    explicit DoubleExpression(DoubleType val) : value_(val)
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    DoubleType value_;
};

class UnsignedExpression : public ExpressionNode
{
  public:
    using UnsignedType = uint64_t;

    explicit UnsignedExpression(UnsignedType val) : value_(val)
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    UnsignedType value_;
};
} // namespace Parser::AST