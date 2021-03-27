#pragma once

#include "Node.h"

#include <cstdint>
#include <vector>
#include <string>

#include "IdentifierExpression.h"
#include "VariableDeclarationStatement.h"
#include "Block.h"

namespace Parser::AST
{
class FunctionDeclarationStatement : public StatementNode
{
  public:
    using ArgListType = std::vector<VariableDeclarationStatement *>;

  public:
    FunctionDeclarationStatement(const IdentifierExpression *type, IdentifierExpression *id, Block *block,
                                 ArgListType &&args)
        : type_(type), id_(id), block_(block), args_{std::move(args)}
    {
    }

    [[nodiscard]] virtual llvm::Value *codegen() override;

    [[nodiscard]] std::vector<VariableDeclarationStatement *> &args()
    {
        return args_;
    }

  private:
    const IdentifierExpression *type_{nullptr};
    IdentifierExpression *id_{nullptr};
    Block *block_{nullptr};

    mutable ArgListType args_{};
};

} // namespace Parser::AST