%option noyywrap
%{
#include <string>

#include "types.h"

#include "parser.hh"

#define YY_DECL extern "C" int yylex()


%}


%%

[ \t]+    ;        // skip white space

[0-9]+            { yylval.integer_value = std::stoi(yytext); return LINE; }

\"[^\"\n]*\"        { yylval.string_value = strdup(yytext); return STRING; }

PRINT            { return PRINT; }

RUN            { return RUN; }

\n            return ENDL;

%%