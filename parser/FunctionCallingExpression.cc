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

    if (callee->arg_size() != arglist_.size())
    {
        CLI::Logger.Instance().Error("Incorrect argument count.");
    }

    std::vector<Value *> args_values{};
    for (const auto &arg : arglist_)
    {
        args_values.push_back(arg->codegen());
        if (!args_values.back())
        {
            return nullptr;
        }
    }

    return Program::Instance().IRBuilder()->CreateCall(callee, args_values, "calltmp");
}