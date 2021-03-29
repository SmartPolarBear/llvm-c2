#include "FunctionCallingExpression.h"
#include "Program.h"
#include "Logging.h"

using namespace llvm;

using namespace Parser::AST;
using namespace CLI;

llvm::Value *FunctionCallingExpression::codegen()
{
    auto callee = Program::Instance().Module()->getFunction(func_->Name());

    if (!callee)
    {
        CLI::Logger.Instance().Error("Unknown function reference.");
    }

    return nullptr;
}