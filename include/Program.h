#pragma once
#include "Singleton.h"

#include "Node.h"
#include "Block.h"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include <vector>
#include <memory>
#include <map>
#include <string>

class Program : public Singleton<Program>
{
  public:
    Program()
        : context_(std::make_unique<llvm::LLVMContext>()),
          module_(std::make_unique<llvm::Module>("llvm-c2", *context_)),
          ir_builder_(std::make_unique<llvm::IRBuilder<>>(*context_))
    {
    }

    Program(const Program &) = delete;
    Program(Program &&) = delete;
    Program &operator=(const Program &) = delete;
    ~Program() = default;

    void SetRoot(Parser::AST::Block *root)
    {
        root_ = root;
    }

    [[nodiscard]] llvm::LLVMContext* Context()
    {
        return context_.get();
    }

    [[nodiscard]] llvm::Module* Module()
    {
        return module_.get();
    }

    [[nodiscard]] llvm::IRBuilder<>* IRBuilder()
    {
        return ir_builder_.get();
    }

    [[nodiscard]] auto &NamedValues()
    {
        return named_values_;
    }

    void Generate();

  private:
    Parser::AST::Block *root_;

    std::unique_ptr<llvm::LLVMContext> context_;
    std::unique_ptr<llvm::Module> module_;
    std::unique_ptr<llvm::IRBuilder<>> ir_builder_;

    std::unordered_map<std::string, llvm::Value *> named_values_;
};
