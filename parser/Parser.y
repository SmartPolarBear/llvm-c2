
%{
    
#define BISONLEXFILE
#include "BisonFlexCommon.h"
#undef BISONLEXFILE

extern "C" int yylex();
extern "C" int yyparse();

extern "C" FILE *yyin;

void yyerror(const char *s);

%}

// token type definition
%union {
    std::string* string_value;
    int64_t token_value;
    ExpressionNode *expr;
    StatementNode *stmt;
    Block *block;
}

// constant tokens
%token ENDL 
%token SUB
%token DIM

// terminal symbols
%token <string_value> TSTRING TIDENTIFIER TINTEGER TDOUBLE
%token <token_value> TCEQ TCNE TCLT TCLE TCGT TCGE TEQL
%token <token_value> TLPAREN TRPAREN TCOMMA TDOT
%token <token_value> TPLUS TMINUS TMUL TDIV

%left TPLUS TMINUS
%left TMUL TDIV

%type <stmt> stmt var_decl
%type <block> program stmts block

%start program

%% /* Grammar rules and actions follow */

program : stmts {}
    ;

stmts : stmt { $$ = new Block{}; $$->statements().push_back($<stmt>1);}
    | stmts stmt { $1->statements().push_back($<stmt>2); }
    ;

stmt : var_decl
    ;

var_decl :
    ;

%%