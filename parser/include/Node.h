#pragma once

#include <cstdlib>

#include <llvm/IR/Value.h>

namespace Parser::AST
{

class Node
{
  public:
    virtual ~Node()
    {
    }

    virtual llvm::Value *codegen() = 0;
};

class ExpressionNode : public Node
{
};

class StatementNode : public Node
{
};

} // namespace Parser::AST
