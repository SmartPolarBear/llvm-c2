#pragma once
#include <cstdlib>

extern "C" int yylex();
extern "C" int yyparse();

extern "C" FILE *yyin;

namespace Parser
{
class Node
{
public:

};
}
