#include "VariableDeclarationStatement.h"
#include "Program.h"

using namespace Parser::AST;
using namespace llvm;


llvm::Value *VariableDeclarationStatement::codegen()
{
    auto val = Program::Instance().NamedValues()[this->id_];
    return nullptr;
}