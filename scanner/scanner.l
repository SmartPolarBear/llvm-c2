%option noyywrap
%{
#include <cstdio>
#include <cstdint>

#include <iostream>
#include <string_view>
#include <memory>

#include "types.h"
#include "parser.hh"

using namespace std;

#define YY_DECL extern "C" int yylex()

%}


%%

[ \t]+    ;        // skip white space

[0-9]+            { yylval.integer_value = std::stoi(yytext); return LINE; }

\"[^\"\n]*\"      { yylval.string_value = new string{yytext}; return STRING; }

PRINT            { return PRINT; }

RUN            { return RUN; }

\n            return ENDL;

%%