#pragma once
#include "Singleton.h"

#include "Node.h"

#include <vector>
#include <memory>

class Program : Singleton<Program>
{
  public:
    void add(std::unique_ptr<Parser::AST::Node> statement);

  private:
    std::vector<std::unique_ptr<Parser::AST::Node>> statements_;
};

