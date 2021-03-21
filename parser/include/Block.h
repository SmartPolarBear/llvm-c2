#pragma once

#include "Node.h"
#include <cstdint>
#include <vector>

namespace Parser::AST
{
class Block : public Node
{
  public:
    Block() = default;

    std::vector<Node*> &statements()
    {
        return statements_;
    }

    [[nodiscard]] llvm::Value *codegen() override;

  private:
    std::vector<Node*> statements_{};
};
} // namespace Parser::AST