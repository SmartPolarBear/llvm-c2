#include <Program.h>

void Program::add(std::unique_ptr<Parser::AST::Node> statement)
{
    statements_.push_back(std::move(statement));
}