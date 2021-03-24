#pragma once

#include "Node.h"
#include <cstdint>
#include <string>

#include "IdentifierExpression.h"

namespace Parser::AST
{
class VariableDeclarationStatement : public StatementNode
{
  public:
    VariableDeclarationStatement(const IdentifierExpression *type, IdentifierExpression *id)
        : type_(type), id_(id), assignment_expression_{nullptr}
    {
    }

    VariableDeclarationStatement(const IdentifierExpression *type, IdentifierExpression *id,
                                 ExpressionNode *assignment_expression)
        : type_(type), id_(id), assignment_expression_{assignment_expression}
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

  private:
    const IdentifierExpression *type_{nullptr};
    IdentifierExpression *id_{nullptr};
    ExpressionNode *assignment_expression_{nullptr};
};

} // namespace Parser::AST