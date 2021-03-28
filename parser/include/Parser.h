#pragma once

#include <cstdio>

extern "C" int yylex();
extern "C" int yyparse();

extern "C" FILE *yyin;
