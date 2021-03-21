%option noyywrap
%{
#define BISONLEXFILE
#include "BisonFlexCommon.h"
#undef BISONLEXFILE

#include "Parser.hh"

#define YY_DECL extern "C" int yylex()

%}


%%

[ \t]+                  ;        // skip white space

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.string_value = new string{yytext}; return TIDENTIFIER;}

[0-9]+                  { yylval.string_value = new string{yytext}; return TINTEGER; }

[0-9]+.[0-9]*           { yylval.string_value = new string{yytext}; return TDOUBLE; }

\"[^\"\n]*\"            { yylval.string_value = new string{yytext}; return TSTRING; }

"="                     { return yylval.token_value = TEQL;}

"=="                    { return yylval.token_value = TCEQ;}

"!="                    { return yylval.token_value = TCNE;}

"<"                     { return yylval.token_value = TCLT;}

"<="                    { return yylval.token_value = TCLE;}

">"                     { return yylval.token_value = TCGT;}

">="                    { return yylval.token_value = TCGE;}

"("                     { return yylval.token_value = TLPAREN;}

")"                     { return yylval.token_value = TRPAREN;}

"."                     { return yylval.token_value = TDOT;}

","                     { return yylval.token_value = TCOMMA;}

"+"                     { return yylval.token_value = TPLUS;}

"-"                     { return yylval.token_value = TMINUS;}

"*"                     { return yylval.token_value = TMUL;}

"/"                     { return yylval.token_value = TDIV;}

\n                     { return ENDL;}

.                      { std::cout << "Error: Unknown token "<< yytext << std::endl; yyterminate();}}

%%