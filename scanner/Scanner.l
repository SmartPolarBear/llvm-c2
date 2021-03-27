%option noyywrap
%{
#define BISONLEXFILE
#include "BisonFlexCommon.inc"
#undef BISONLEXFILE

#include "Parser.hh"

#define YY_DECL extern "C" int yylex()

%}


%%

[ \t\n]+                  ;        // skip white space

[a-zA-Z_][a-zA-Z0-9_]*  {yylval.string_value=new std::string{yytext,static_cast<std::string::size_type>(yyleng)}; return TIDENTIFIER;}

[0-9]+.[0-9]*          { yylval.floating_value=std::stold(yytext);return TDOUBLE;}

[0-9]+u                { yylval.uint_value=std::stoull(yytext); return TUNSIGNED;}

[0-9]+                 { yylval.integer_value=std::stoll(yytext); return TINTEGER;}

"="                     return yylval.token_value=TEQL;

"=="                    return yylval.token_value=TCEQ;

"!="                    return yylval.token_value=TCNE;

"<"                     return yylval.token_value=TCLT;

"<="                    return yylval.token_value=TCLE;

">"                     return yylval.token_value=TCGT;

">="                    return yylval.token_value=TCGE;

"("                     return yylval.token_value=TLPAREN;

")"                     return yylval.token_value=TRPAREN;

"{"                     return yylval.token_value=TLBRACE;

"}"                     return yylval.token_value=TRBRACE;

"."                     return yylval.token_value=TDOT;

","                     return yylval.token_value=TCOMMA;

"+"                     return yylval.token_value=TPLUS;

"-"                     return yylval.token_value=TMINUS;

"*"                     return yylval.token_value=TMUL;

"/"                     return yylval.token_value=TDIV;

.                      { std::cout << "Error: Unknown token "<< yytext << std::endl; yyterminate();}

%%