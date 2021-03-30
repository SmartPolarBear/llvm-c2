#pragma once
#include "Singleton.h"

#include <string_view>
#include <iostream>

#include <fmt/core.h>
#include <fmt/color.h>

namespace CLI
{
class Logger : public Singleton<Logger>
{
  public:
    void Error(std::string_view sv)
    {
        fmt::print(fg(fmt::color::red), "ERROR: {}", sv);
    }

    void Warning(std::string_view sv)
    {
    }

    void Info(std::string_view sv)
    {
    }
};
} // namespace CLI
