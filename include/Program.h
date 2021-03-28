#pragma once
#include "Singleton.h"

#include "Node.h"
#include "Block.h"

#include <vector>
#include <memory>

class Program : public Singleton<Program>
{
  public:
    Program() = default;
    ~Program() = default;

    void SetRoot(Parser::AST::Block *root)
    {
        root_ = root;
    }

    

  private:
    Parser::AST::Block *root_;
};
